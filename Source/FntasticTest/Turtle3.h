// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "Nest.h"
#include "Turtle3.generated.h"


UCLASS()
class FNTASTICTEST_API ATurtle3 : public ATurtle
{
	GENERATED_BODY()

protected:
	FVector PreviousLocation;

public:

	virtual void MoveToWaypoint() override;
	void MoveBack();

};
