// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
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
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement component"));
	
}

void ATank::AimAt(FVector HitLocation)
{
	   // UE_LOG(LogTemp, Warning, TEXT("Tank Tank Aim AT "));
		TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
		
	
}

void ATank::Fire()
{

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	 //UE_LOG(LogTemp, Warning, TEXT("Tank Fires "));
	 if (Barrel && isReloaded)
	 {
		 auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
															  Barrel->GetSocketLocation(FName("Projectile")),
															  Barrel->GetSocketRotation(FName("Projectile"))		
															);

		 Projectile->LaunchProjectile(LaunchSpeed);

		 LastFireTime = FPlatformTime::Seconds();
	 }

	 

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

