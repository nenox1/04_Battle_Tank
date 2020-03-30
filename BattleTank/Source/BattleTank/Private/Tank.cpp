// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);

	Barrel = BarrelToSet;

	}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);

	Turret = TurretToSet;
}

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
	
}

void ATank::AimAt(FVector HitLocation)
{
	   // UE_LOG(LogTemp, Warning, TEXT("Tank Tank Aim AT "));
		TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
		
	
}

void ATank::Fire()
{
	 //UE_LOG(LogTemp, Warning, TEXT("Tank Fires "));
	 if (!Barrel) { return; }

	 GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, 
		                                 Barrel->GetSocketLocation(FName("Projectile")), 
		                                 Barrel->GetSocketRotation(FName("Projectile"))
								);

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

