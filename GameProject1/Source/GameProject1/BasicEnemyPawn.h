// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasicEnemyPawn.generated.h"

UCLASS()
class GAMEPROJECT1_API ABasicEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasicEnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = AI)
		class UBehaviorTree* behaviorTree;

	UPROPERTY(VisibleAnywhere, Category = AI)
		class UPawnSensingComponent* pawnSensingComp;

private:
	UFUNCTION()
		void OnPlayerCaught(APawn* Pawn);
	
};
