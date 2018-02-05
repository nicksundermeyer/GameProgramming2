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
	
	
virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	float Speed;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward();	
	
};
