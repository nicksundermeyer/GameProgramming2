// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/GameModeBase.h"
#include "GameProject1GameMode.generated.h"

UCLASS(minimalapi)
class AGameProject1GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AGameProject1GameMode();

	// overriding startplay to perform actions when game starts
	virtual void StartPlay() override;

protected:
	virtual void HandleMatchHasStarted() override;
	virtual void HandleMatchHasEnded() override;

};



