// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT1_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		APawn *controlPawn;
	
	
};
