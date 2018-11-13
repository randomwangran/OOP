// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public: 
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection) const;


private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .33333f;

};
