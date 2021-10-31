// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TurtleAIController.h"
#include "Waypoint.h"
#include "Turtle.generated.h"

UCLASS()
class FNTASTICTEST_API ATurtle : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		UParticleSystem* SpawnEmitter;
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		USoundBase* SpawnSound;
	UPROPERTY(EditDefaultsOnly, Category = "Death")
		UParticleSystem* DeathEmitter;


	virtual void MoveToWaypoint();
	void FindWaypointRef();
	AActor* GetWaypointRef();

	UFUNCTION(BlueprintCallable)
		bool GetIsDead();

	void SetIsDead();


protected:

	UPROPERTY(VisibleAnywhere, Category = "Death")
		bool isDead;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Waypoint")
		int ToWaypoint;
	AActor* WaypointRef;
	TArray<AActor*> Waypoints;

};
