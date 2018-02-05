// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"
#include "MyPawn.h"

void AMyPlayerController::SetupInputComponent()
{
    // print(TEXT("SetupInputComponent() running for MyPlayerController."));
    // call the parent first
    Super::SetupInputComponent();

    // now bind stuff, note that we can simply use InputComponent,because we
    // inherit this from AActor, and it will have been created by now (well we hope)
    check(InputComponent);

    // bind actions
    InputComponent->BindAction("Forward", IE_Pressed, this, &AMyPlayerController::MoveForward);

    // bind defined axes
    // InputComponent->BindAxis("Horizontal", this, &AMyPlayerController::MoveForward);
    // InputComponent->BindAxis("Vertical", this, &AMyPlayerController::MoveRight);
}

void AMyPlayerController::MoveForward()
{
    // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Moving forward"));
    AMyDefaultPawn *pawn = Cast<AMyDefaultPawn>(GetPawn());
    if (pawn)
    {
        pawn->MoveForward();
    }
}