// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Turtle3.h"

void ATurtle3::MoveToWaypoint()
{
	ATurtleAIController* TurtleAIController = Cast<ATurtleAIController>(GetController());

	if (TurtleAIController)
	{
		PreviousLocation = this->GetActorLocation();
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle, this, &ATurtle3::MoveBack, 1.f, false);
		TurtleAIController->MoveToActor(WaypointRef, 5.f, false);
	}
}

void ATurtle3::MoveBack()
{
	if (WaypointRef->GetActorLocation().Equals(this->GetActorLocation(), 100.0f))return;

	ATurtleAIController* TurtleAIController = Cast<ATurtleAIController>(GetController());

	if (TurtleAIController)
	{
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle, this, &ATurtle3::MoveToWaypoint, 0.5f, false);
		TurtleAIController->MoveToLocation(PreviousLocation, 5.f, false);
	}
}
