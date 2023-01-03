// Copyright Epic Games, Inc. All Rights Reserved.


#include "BatteryManGameModeBase.h"
#include "CBatteryMan.h"	
#include "UObject/ConstructorHelpers.h"

ABatteryManGameModeBase::ABatteryManGameModeBase()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/_Game/BatteryMan/BP/Character/BP_BatteryMan"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}