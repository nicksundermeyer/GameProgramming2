// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "MyDefaultPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase() : AGameModeBase()
{
    DefaultPawnClass = AMyDefaultPawn::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
}

AMyGameModeBase::~AMyGameModeBase()
{
}