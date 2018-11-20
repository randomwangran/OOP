// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
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

	//debugging
	//ATankPlayerController aPlayer;

    //FVector playerLocation = aPlayer.ATankPlayerController::GetPlayerLocation();

	//UE_LOG(LogTemp, Warning, TEXT("Find: %s"), *(playerLocation.ToString()))
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } // Note the !, very important
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	//FVector playerLocation(1, 1, 1);
	
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}