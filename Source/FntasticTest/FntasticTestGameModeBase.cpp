// Copyright Epic Games, Inc. All Rights Reserved.


#include "FntasticTestGameModeBase.h"
#include "MyPlayerController.h"

AFntasticTestGameModeBase::AFntasticTestGameModeBase()
{
	DefaultPawnClass = NULL;
	PlayerControllerClass = AMyPlayerController::StaticClass();
}