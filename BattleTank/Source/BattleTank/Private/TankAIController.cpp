// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"




void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	//float LaunchSpeed;

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//ControlledTank->Fire();

	}



}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

ATank* ATankAIController::GetControlledTank() const
{
	//UE_LOG(LogTemp, Warning, TEXT("Player Controler"), Cast<ATank>(GetPawn()).);
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}
