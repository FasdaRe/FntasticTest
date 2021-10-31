// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Turtle.h"

// Sets default values
ATurtle::ATurtle()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	isDead = false;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);

}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	FVector Loc = this->GetActorLocation();
	FRotator Rot = this->GetActorRotation();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), SpawnEmitter, Loc, Rot, true);
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), SpawnSound, Loc);
	FindWaypointRef();
	MoveToWaypoint();

}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurtle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurtle::MoveToWaypoint()
{
	ATurtleAIController* TurtleAIController = Cast<ATurtleAIController>(GetController());

	if (TurtleAIController)
	{
		if (WaypointRef)
		{
			TurtleAIController->MoveToActor(WaypointRef, 5.f, false);
		}
	}
}

void ATurtle::FindWaypointRef()
{
	for (AActor* Waypoint : Waypoints)
	{
		AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);

		if (WaypointItr)
		{
			if (WaypointItr->GetWaypointNumber() == ToWaypoint)
			{
				WaypointRef = WaypointItr;
			}
		}
	}
}

AActor* ATurtle::GetWaypointRef()
{
	return WaypointRef;
}

bool ATurtle::GetIsDead()
{
	return isDead;
}

void ATurtle::SetIsDead()
{
	isDead = true;
}


