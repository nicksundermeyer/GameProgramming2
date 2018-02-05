// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameProject1HUD.generated.h"

UCLASS()
class AGameProject1HUD : public AHUD
{
	GENERATED_BODY()

public:
	AGameProject1HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

protected:
	UFont* BigFont;

};

