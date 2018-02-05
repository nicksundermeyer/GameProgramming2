// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameProject1GameMode.h"
#include "GameProject1HUD.h"
#include "GameProject1Character.h"
#include "MyGameStateBase.h"
#include "MainPlayerState.h"
#include "Engine/Engine.h"
#include "GameFramework/GameMode.h"
#include "EngineGlobals.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/NetDriver.h"
#include "GameFramework/LocalMessage.h"
#include "GameFramework/EngineMessage.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/CheatManager.h"
#include "GameDelegates.h"
#include "GameMapsSettings.h"
#include "EngineUtils.h"
#include "UObject/ConstructorHelpers.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

AGameProject1GameMode::AGameProject1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// setup game state class
	GameStateClass = AMyGameStateBase::StaticClass();

	// use our custom HUD class
	HUDClass = AGameProject1HUD::StaticClass();
}

void AGameProject1GameMode::StartPlay()
{
	Super::StartPlay();

	if(GEngine)
	{
		print("StartPlay");
	}
}

void AGameProject1GameMode::HandleMatchHasStarted()
{	
	GameSession->HandleMatchHasStarted();

	// start human players first
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		APlayerController* PlayerController = Iterator->Get();
		if ((PlayerController->GetPawn() == nullptr) && PlayerCanRestart(PlayerController))
		{
			RestartPlayer(PlayerController);
		}
	}

	// Make sure level streaming is up to date before triggering NotifyMatchStarted
	GEngine->BlockTillLevelStreamingCompleted(GetWorld());

	// First fire BeginPlay, if we haven't already in waiting to start match
	GetWorldSettings()->NotifyBeginPlay();

	// Then fire off match started
	GetWorldSettings()->NotifyMatchStarted();

	// if passed in bug info, send player to right location
	const FString BugLocString = UGameplayStatics::ParseOption(OptionsString, TEXT("BugLoc"));
	const FString BugRotString = UGameplayStatics::ParseOption(OptionsString, TEXT("BugRot"));
	if (!BugLocString.IsEmpty() || !BugRotString.IsEmpty())
	{
		for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			APlayerController* PlayerController = Iterator->Get();
			if (PlayerController->CheatManager != nullptr)
			{
				PlayerController->CheatManager->BugItGoString(BugLocString, BugRotString);
			}
		}
	}

	if (IsHandlingReplays() && GetGameInstance() != nullptr)
	{
		GetGameInstance()->StartRecordingReplay(GetWorld()->GetMapName(), GetWorld()->GetMapName());
	}

	if(GEngine)
	{
		print("HandleMatchHasStarted");
	}	
}

void AGameProject1GameMode::HandleMatchHasEnded()
{
	GameSession->HandleMatchHasEnded();

	if (IsHandlingReplays() && GetGameInstance() != nullptr)
	{
		GetGameInstance()->StopRecordingReplay();
	}

	AMyGameStateBase* const MyGameState = Cast<AMyGameStateBase>(GameState);
	MyGameState->setTimer(false);

	if(GEngine)
	{
		print("HandleMatchHasEnded");
	}	
}