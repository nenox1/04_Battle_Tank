// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000;

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	
};
