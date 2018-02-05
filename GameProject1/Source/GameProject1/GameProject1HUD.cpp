// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameProject1HUD.h"
#include "MyGameStateBase.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"

AGameProject1HUD::AGameProject1HUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	// finding font
	static ConstructorHelpers::FObjectFinder<UFont> BigFontOb(TEXT("/Game/UI/HUD/Roboto51"));
	BigFont = BigFontOb.Object;
}


void AGameProject1HUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );

	// draw timer in top right
	float time = GetWorld()->GetGameState<AMyGameStateBase>()->getTimer();
	FText timerText = FText::FromString(FString::SanitizeFloat(time));
	FLinearColor fontColor = FLinearColor(1.0f, 1.0f, 1.0f);
	FCanvasTextItem NewText(FVector2D(300, 10), timerText, BigFont, fontColor);

	//Text Scale
	NewText.Scale.Set(1, 1);

	//Draw
	Canvas->DrawItem(NewText);
}
