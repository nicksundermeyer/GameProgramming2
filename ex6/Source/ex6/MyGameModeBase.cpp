// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase() : AGameModeBase()
{
    DefaultPawnClass = AMyPawn::StaticClass();
    PlayerControllerClass = AMyPlayerController::StaticClass();
}

AMyGameModeBase::~AMyGameModeBase()
{
}