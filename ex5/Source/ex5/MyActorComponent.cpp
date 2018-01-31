// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FQuat newRot = GetOwner()->GetActorQuat() * rotSpeed;

	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("(%f, %f, %f, %f)"), newRot.X, newRot.Y, newRot.Z, newRot.W));
	// FString::Printf(TEXT("(%f, %f, %f, %f)"), rotSpeed.X, rotSpeed.Y, rotSpeed.Z, rotSpeed.W));

	// now set it, a bit of a tedious way to do this
	FTransform t = GetOwner()->GetTransform();
	FTransform nt = FTransform(newRot, t.GetTranslation(), t.GetScale3D());
	GetOwner()->SetActorTransform(nt);
}
