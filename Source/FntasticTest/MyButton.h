// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyButton.generated.h"


UCLASS()
class FNTASTICTEST_API AMyButton : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Spawning")
		TSubclassOf<AActor> ActorToSpawn;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* MainRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* ButtonMesh;

	UFUNCTION()
		void ButtonClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);
	UFUNCTION()
		void SpawnObj(FVector Loc, FRotator Rot);

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "SpawnNumber")
		int SpawnOnNest;
	TArray<AActor*> Nests;
};
