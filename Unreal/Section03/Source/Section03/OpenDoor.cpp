// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Grabber.h"
#define OUT
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//OpenDoor();

	Owner = GetOwner();

}

void UOpenDoor::OpenDoor()
{
	//if (!Owner) { return; }
	//Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	OnOpenRequest.Broadcast();
}

void UOpenDoor::CloseDoor()
{
	if (!Owner) { return; }
	Owner->SetActorRotation(FRotator(0.0f, -90.0f, 0.0f));

}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMassOfActorsOnPlate() > 50.f) // TODO make into parameter
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
	}
}


float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
	float TotalMass = 0.f;

	TArray<AActor*> OverlappingActors;
	TArray<ABrush*> Component;
	if (PressurePlate)
	{
		PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PressurePlate is a null pointer"))
	}

	for (const auto &Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s is on the pressure plate"), *(Actor->GetName()))

	}
	return TotalMass;
}