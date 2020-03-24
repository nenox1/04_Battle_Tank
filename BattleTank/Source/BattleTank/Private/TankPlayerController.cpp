// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (ControlledTank) {
		//UE_LOG(LogTemp, Warning, TEXT("Player posessing a Tank:%s"), *(ControlledTank->GetName()));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("Player NOT posessing a Tank"));			
	}


	
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//UE_LOG(LogTemp, Warning, TEXT("Player Controler"), Cast<ATank>(GetPawn()).);
	return Cast<ATank>(GetPawn());
}