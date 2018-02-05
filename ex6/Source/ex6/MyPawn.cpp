// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> asset(TEXT("/Game/Meshes/Shape_Cone.Shape_Cone"));
	if (asset.Succeeded())
	{
		mesh->SetStaticMesh(asset.Object);
		mesh->SetWorldScale3D(FVector(.50f));
	}

	RootComponent = mesh;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	// movement components get all the inputs and store them in an input vector
	// so we can just grab this, multiply it by the speed, and move our actor
	FVector v = GetMovementComponent()->GetLastInputVector();
	if (!v.IsNearlyZero())
	{
		v = v.GetClampedToMaxSize(1.0f);
		v *= Speed;
		SetActorLocation(GetActorLocation() + (v * DeltaTime));
		// get rid of the last input vector
		GetMovementComponent()->ConsumeInputVector();
	}
	
        // I don't like the way they designed this because it uses FRotator, but I can also write less code using this
	FRotator rot = GetControlRotation();
	if (!rot.IsNearlyZero())
	{
		// set the rotation of this pawn
		SetActorRotation(rot);
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// move forwad

void AMyPawn::MoveForward()
{
	UPawnMovementComponent *comp = GetMovementComponent();

	FVector forward = Speed * GetActorForwardVector();
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("MyPawn MoveForward: (%f, %f, %f)"), forward.X, forward.Y, forward.Z));
	// the movement component accumulates these inputs into a single vector that we can then process in Tick 
	comp->AddInputVector(forward, false);
}