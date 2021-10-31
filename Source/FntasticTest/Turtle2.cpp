// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Turtle2.h"

void ATurtle2::MoveToWaypoint()
{
	ATurtleAIController* TurtleAIController = Cast<ATurtleAIController>(GetController());

	if (TurtleAIController)
	{
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle, this, &ATurtle2::StopMove, 1.f, false);
		TurtleAIController->MoveToActor(WaypointRef, 5.f, false);
	}
}

void ATurtle2::StopMove()
{
	if (WaypointRef->GetActorLocation().Equals(this->GetActorLocation(), 100.0f))return;

	ATurtleAIController* TurtleAIController = Cast<ATurtleAIController>(GetController());

	if (TurtleAIController)
	{
		FTimerHandle Handle;
		GetWorldTimerManager().SetTimer(Handle, this, &ATurtle2::MoveToWaypoint, 0.5f, false);
		TurtleAIController->StopMovement();
	}

}
