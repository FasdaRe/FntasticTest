// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Waypoint.h"


int AWaypoint::GetWaypointNumber()
{
	return WaypointNumber;
}

AWaypoint::AWaypoint()
{
	MainRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Main0"));
}
