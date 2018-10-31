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

}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}



