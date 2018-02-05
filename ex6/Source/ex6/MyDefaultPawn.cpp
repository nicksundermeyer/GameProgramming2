// Fill out your copyright notice in the Description page of Project Settings.

#include "MyDefaultPawn.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/DamageType.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "Components/PrimitiveComponent.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Engine/Canvas.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealEngine.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "DisplayDebugHelpers.h"
#include "Engine/InputDelegateBinding.h"
#include "Interfaces/NetworkPredictionInterface.h"
#include "GameFramework/PlayerState.h"
#include "Components/PawnNoiseEmitterComponent.h"
#include "GameFramework/GameNetworkManager.h"

#define print(text) if(GEngine)  GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);

void AMyDefaultPawn::PossessedBy(AController* NewController)
{
	AController* const OldController = Controller;

	Controller = NewController;
	ForceNetUpdate();

	if (Controller->PlayerState != NULL)
	{
		PlayerState = Controller->PlayerState;
	}

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (GetNetMode() != NM_Standalone)
		{
			SetReplicates(true);
			SetAutonomousProxy(true);
		}
	}
	else
	{
		CopyRemoteRoleFrom(GetDefault<APawn>());
	}

	// dispatch Blueprint event if necessary
	if (OldController != NewController)
	{
		ReceivePossessed(Controller);
	}

	print(NewController->GetName());

}

void AMyDefaultPawn::MoveForward(float Val)
{
	if (Val != 0.f)
	{
		if (Controller)
		{
			FRotator const ControlSpaceRot = Controller->GetControlRotation();

			// transform to world space and add it
			AddMovementInput(FRotationMatrix(ControlSpaceRot).GetScaledAxis(EAxis::X), Val);
		}
	}

	print(FString::SanitizeFloat(Val));
}