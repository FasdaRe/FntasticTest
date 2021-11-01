// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Waypoint.generated.h"

UCLASS()
class FNTASTICTEST_API AWaypoint : public AActor
{
	GENERATED_BODY()

public:

	int GetWaypointNumber();

	AWaypoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* MainRoot;

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"),Category = "WaypointNumber")
		int WaypointNumber;
};

