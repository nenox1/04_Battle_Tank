// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

void ATank::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);

	//UE_LOG(LogTemp, Warning, TEXT("Tank Set Barrel reference "));
	//Barrel = BarrelToSet;


}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
	//UE_LOG(LogTemp, Warning, TEXT("Tank construtor "));

}

void ATank::AimAt(FVector HitLocation)
{
	   // UE_LOG(LogTemp, Warning, TEXT("Tank Tank Aim AT "));
		TankAimingComponent->AimAt(HitLocation);
		
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

