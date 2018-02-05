// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "Engine/Engine.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"

#define print(text) if(GEngine)  GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, text);

// Sets default values
AMyPawn::AMyPawn()
{
 	//Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> asset(TEXT("/Game/Meshes/Shape_Cube.Shape_Cube"));
	if (asset.Succeeded())
	{
		print("succeeded");
		mesh->SetStaticMesh(asset.Object);
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

	if (moveForward)
	{
		MoveForward();
	}

	// movement components get all the inputs and store them in an input vector
	// so we can just grab this, multiply it by the speed, and move our actor
	FVector v = GetMovementComponent()->GetLastInputVector();
	//print(FString::Printf(TEXT("x: %f y: %f z: %f"), v.X, v.Y, v.Z));
	if (!v.IsNearlyZero())
	{
		v = v.GetClampedToMaxSize(1.0f);
		v *= 1000;
		SetActorLocation(GetActorLocation() + (v * DeltaTime));
		//print(FString::Printf(TEXT("x: %f y: %f z: %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
		// get rid of the last input vector
		GetMovementComponent()->ConsumeInputVector();
	}
	
    // I don't like the way they designed this because it uses FRotator, but I can also write less code using this
	//FRotator rot = GetControlRotation();
	//if (!rot.IsNearlyZero())
	//{
	//	// set the rotation of this pawn
	//	SetActorRotation(rot);
	//}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Forward", IE_Pressed, this, &AMyPawn::startMovingForward);
	PlayerInputComponent->BindAction("Forward", IE_Released, this, &AMyPawn::stopMovingForward);

	PlayerInputComponent->BindAxis("Vertical", this, &AMyPawn::VerticalRotate);
	PlayerInputComponent->BindAxis("Horizontal", this, &AMyPawn::HorizontalRotate);
}

void AMyPawn::startMovingForward()
{
	moveForward = true;
}

void AMyPawn::stopMovingForward()
{
	moveForward = false;
}

// move forwad
void AMyPawn::MoveForward()
{
	//print("moving pawn forward");
	UPawnMovementComponent *comp = GetMovementComponent();

	FVector forward = GetActorForwardVector();

	// the movement component accumulates these inputs into a single vector that we can then process in Tick 
	AddMovementInput(forward);
}

// rotation
void AMyPawn::VerticalRotate(float Rate)
{
	FVector right = GetActorRightVector();
	FQuat newRot =  FQuat(right, Rate*0.03) * GetActorQuat();
	//print(FString::Printf(TEXT("x: %f y: %f z: %f w: %f"), newRot.X, newRot.Y, newRot.Z, newRot.W));

	FTransform t = GetTransform();
	FTransform nt = FTransform(newRot, t.GetTranslation(), t.GetScale3D());
	SetActorTransform(nt);
}

void AMyPawn::HorizontalRotate(float Rate)
{
	FVector up = GetActorUpVector();
	FQuat newRot = FQuat(up, Rate*0.03) * GetActorQuat();
	//print(FString::Printf(TEXT("x: %f y: %f z: %f w: %f"), newRot.X, newRot.Y, newRot.Z, newRot.W));

	FTransform t = GetTransform();
	FTransform nt = FTransform(newRot, t.GetTranslation(), t.GetScale3D());
	SetActorTransform(nt);
}
