// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/GameState.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT1_API AMyGameStateBase : public AGameState
{
	GENERATED_BODY()

public:
	AMyGameStateBase();

	// update current time
	UFUNCTION(BlueprintCallable, Category = "Timer")
		void updateTimer(float ct);

	// timer start time, set when actor hits trigger
	UFUNCTION(BlueprintCallable, Category = "Timer")
		void setStartTime(float st);

	// get current time
	UFUNCTION(BlueprintCallable, Category = "Timer")
		void setTimer(bool in) { timer = in; }

	UFUNCTION(BlueprintCallable, Category="Timer")
		float getTimer() { return elapsedTime; }

private:
	float startTime;
	float elapsedTime;
	bool timer;
	
};
