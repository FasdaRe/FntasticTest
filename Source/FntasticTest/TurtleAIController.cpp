// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Turtle.h"
#include "TurtleAIController.h"


void ATurtleAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	ATurtle* Turtle = Cast<ATurtle>(GetPawn());
	FVector Offset = { 5,5,5 };
	if (Turtle)
	{
		if (Turtle->GetWaypointRef()->GetActorLocation().Equals(Turtle->GetActorLocation(), 100.0f))
		{
			FTimerHandle Handle;
			Turtle->SetIsDead();
			GetWorldTimerManager().SetTimer(Handle, this, &ATurtleAIController::Destroy, 1.f, false);
		}

	}
}

void ATurtleAIController::Destroy()
{
	ATurtle* Turtle = Cast<ATurtle>(GetPawn());

	if (Turtle)
	{
		FVector Loc = Turtle->GetActorLocation();
		FRotator Rot = Turtle->GetActorRotation();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
			Turtle->DeathEmitter, Loc, Rot, true);
		Turtle->Destroy();
	}
}
