// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TurtleAIController.generated.h"



UCLASS()
class FNTASTICTEST_API ATurtleAIController : public AAIController
{
	GENERATED_BODY()

		void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	void Destroy();
};
