// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameProject2GameMode.h"
#include "GameProject2Pawn.h"

AGameProject2GameMode::AGameProject2GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGameProject2Pawn::StaticClass();
}

