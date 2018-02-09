// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicEnemyPawn.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Engine/Engine.h"
#include "Perception/PawnSensingComponent.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

// Sets default values
ABasicEnemyPawn::ABasicEnemyPawn()
{
	// initialize sensing
	pawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("pawnSensingComp"));
	pawnSensingComp->SetPeripheralVisionAngle(90.f);
}

// Called when the game starts or when spawned
void ABasicEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (pawnSensingComp)
	{
		// call onplayercaught when enemy sees player pawn
		pawnSensingComp->OnSeePawn.AddDynamic(this, &ABasicEnemyPawn::OnPlayerCaught);
	}
}

// Called to bind functionality to input
void ABasicEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
}

void ABasicEnemyPawn::OnPlayerCaught(APawn* pawn)
{
	// get reference to player controller
	AEnemyAIController* controller = Cast<AEnemyAIController>(GetController());

	if (controller)
	{
		print("You have been caught!");
		//controller->SetPlayerCaught(pawn);
	}
}

