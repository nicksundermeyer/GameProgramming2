// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "MyDefaultPawn.h"
#include "MyPawn.h"
#include "MyPlayerController.h"
#include "MyGameStateBase.h"
#include "MyPlayerState.h"
#include "Engine/Engine.h"

#define print(text) if(GEngine)  GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);

AMyGameModeBase::AMyGameModeBase() : AGameModeBase()
{
    // GameStateClass = AMyGameStateBase::StaticClass();
    DefaultPawnClass = AMyPawn::StaticClass();
    // PlayerControllerClass = AMyPlayerController::StaticClass();
    // PlayerStateClass = AMyPlayerState::StaticClass();
}

AMyGameModeBase::~AMyGameModeBase()
{
}
