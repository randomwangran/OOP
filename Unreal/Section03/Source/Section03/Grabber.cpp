// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#define OUT
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber is here!"));

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	/// get palyer's view
	FVector PlayerPointLocation;
	FRotator PlayerPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	OUT	PlayerPointLocation,
	OUT PlayerPointRotation
	);
	
	FString PlayerLocation = PlayerPointLocation.ToString();
	FString PlayerRotation = PlayerPointRotation.ToString();

	//UE_LOG(LogTemp, Warning, TEXT("Player is at %s, with a roation: %s"), *PlayerLocation, *PlayerRotation);
	float Reach = 100.0f;
	FVector LineTraceEnd = PlayerPointLocation + PlayerPointRotation.Vector()* Reach;
	
	
	DrawDebugLine(
		GetWorld(),
		PlayerPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	/// set query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;


	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	AActor* Actor = Hit.GetActor();

	if (Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Laser is pointing at: %s"), *(Actor->GetName()))
	}
	// ...
}