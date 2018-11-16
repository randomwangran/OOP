// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller pocessing: %s"), *(ControlledTank->GetName()))
	}

	auto PlayerTank = GetWorld()->GetFirstPlayerController();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't find player tank."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Find: %s"), *(PlayerTank->GetName()))
	}

}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}



ATank* ATankAIController::GetPlayerTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector hitLocation(1,1,1);
	
	GetControlledTank()->AimAt(hitLocation);

}