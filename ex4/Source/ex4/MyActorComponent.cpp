// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"
#include <iostream>

// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
	UActorComponent::RegisterComponent();

	// set up LocalTransform
	if (myParent == nullptr)
	{
		LocalTransform = GetOwner()->GetTransform();
		LocalTransform.SetScale3D(FVector(1, 1, 1));
	}
}

// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (myParent)
	{
		FTransform newTransform = myParent->GetTransform() * LocalTransform;
		GetOwner()->SetActorTransform(newTransform);
	}

	LocalTransform.SetRotation(LocalTransform.GetRotation());
}

// Helper functions
void UMyActorComponent::Scale(FVector newScale)
{
	LocalTransform.SetScale3D(newScale);
}

void UMyActorComponent::Rotate(FQuat newRot)
{
	LocalTransform.SetRotation(LocalTransform.GetRotation() + newRot);
}
void UMyActorComponent::Translate(FVector newTrans)
{
	LocalTransform.SetTranslation(LocalTransform.GetTranslation() + newTrans);
}