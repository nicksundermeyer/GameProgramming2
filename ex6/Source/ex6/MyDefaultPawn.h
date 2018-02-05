// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "MyDefaultPawn.generated.h"

/**
 * 
 */
UCLASS()
class EX6_API AMyDefaultPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	virtual void PossessedBy(AController* NewController) override;

	UFUNCTION(BlueprintCallable, Category = "Pawn")
		virtual void MoveForward(float Val) override;

};
