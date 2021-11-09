// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "Kismet/GameplayStatics.h"
#include "Nest.h"
#include "MyButton.h"


// Sets default values
AMyButton::AMyButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MainRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Main0"));
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh0"));
	ButtonMesh->AttachTo(MainRoot);
	ButtonMesh->OnClicked.AddDynamic(this, &AMyButton::ButtonClicked);

}

// Called when the game starts or when spawned
void AMyButton::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANest::StaticClass(), Nests);
	Active = true;
}

// Called every frame
void AMyButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyButton::ButtonClicked(UPrimitiveComponent* ClickedComp, FKey ButtonPressed)
{
	if (Active) {
		FVector Loc;
		FRotator Rot;
		for (AActor* Nest : Nests)
		{
			ANest* NestItr = Cast<ANest>(Nest);

			if (NestItr)
			{
				if (NestItr->GetNestNumber() == SpawnOnNest)
				{
					Loc = NestItr->GetActorLocation();
					Rot = NestItr->GetActorRotation();
				}
			}
		}


		SpawnObj(Loc, Rot);
		FTimerHandle Handle;
		Active = false;
		this->SetActorLocation(this->GetActorLocation() + FVector{5, 0, 0});
		GetWorldTimerManager().SetTimer(Handle, this, &AMyButton::Activate, 1.5f, false);
	}
}

void AMyButton::Activate()
{
	Active = true;
	this->SetActorLocation(this->GetActorLocation() - FVector{ 5, 0, 0 });
}

void AMyButton::SpawnObj(FVector Loc, FRotator Rot)
{
	FActorSpawnParameters SpawnParam;
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Loc, Rot, SpawnParam);
}
