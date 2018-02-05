// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameStateBase.h"
#include "Engine/Engine.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White,text)

AMyGameStateBase::AMyGameStateBase() :Super()
{
	print("Created game state");
}

void AMyGameStateBase::updateTimer(float ct)
{
	if (timer)
	{
		elapsedTime = ct - startTime;
	}
}

void AMyGameStateBase::setStartTime(float st)
{
	if (timer == false)
	{
		startTime = st;
		timer = true;
	}
	print("Started timer");
}
