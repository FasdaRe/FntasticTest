// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Turtle.h"
#include "Turtle2.generated.h"



UCLASS()
class FNTASTICTEST_API ATurtle2 : public ATurtle
{
	GENERATED_BODY()

public:

	virtual void MoveToWaypoint() override;
	void StopMove();

};
