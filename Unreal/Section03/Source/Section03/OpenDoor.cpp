// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

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

   	FString ObjectName = GetOwner()->GetName();

	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);
	AActor* Owner = GetOwner();
	
	Owner->SetActorRotation(NewRotation);
	//float Owner = GetOwner()->GetTransform().Rotator().Yaw;

	//UE_LOG(LogTemp, Warning, TEXT("%s has a rotation of  %d"), *ObjectName,Owner);
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

