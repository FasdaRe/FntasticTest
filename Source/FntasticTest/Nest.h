// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Nest.generated.h"


UCLASS()
class FNTASTICTEST_API ANest : public AStaticMeshActor
{
	GENERATED_BODY()

public:

	int GetNestNumber();

private:

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "NestNumber")
		int NestNumber;
};
