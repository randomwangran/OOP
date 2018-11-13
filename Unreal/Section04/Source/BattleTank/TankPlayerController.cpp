// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player controller pocessing: %s"), *(ControlledTank->GetName()))
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector hitLocation;

	if ( GetSightRayHitLocation(hitLocation) )
	{
		// bool UE_LOG(LogTemp, Warning, TEXT("Look direction, %s"), *hitLocation.ToString())
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation;
	ScreenLocation.X = ViewportSizeX * CrossHairXLocation;
	ScreenLocation.Y = ViewportSizeY * CrossHairYLocation;

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("World direction is, %s"), *LookDirection.ToString())

		GetLookVectorHitLocation(LookDirection);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // discarded

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection) const
{
	FHitResult Hit;

	/// get palyer's view
	FVector PlayerPointLocation;
	FRotator PlayerPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT	PlayerPointLocation,
		OUT PlayerPointRotation
	);

	float Reach = 1000000.f;
	FVector LineTraceEnd = LookDirection * Reach;


	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());


	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		PlayerPointLocation,
		LineTraceEnd,
		ECollisionChannel::ECC_Visibility,
		TraceParameters,
		ECollisionResponse::ECR_Block
	)) {

		AActor* PointingAtWhat = Hit.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("Crosshair is pointing at %s"), *(PointingAtWhat->GetTargetLocation().ToString()))

		return true;
	}
	else
		return false;
}