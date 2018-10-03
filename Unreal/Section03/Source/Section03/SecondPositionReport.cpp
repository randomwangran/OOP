// Fill out your copyright notice in the Description page of Project Settings.

#include "SecondPositionReport.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
USecondPositionReport::USecondPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USecondPositionReport::BeginPlay()
{
	Super::BeginPlay();

	//FString ObjectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("!Position report for! -by Ran"));
	//UE_LOG(LogTemp, Warning, TEXT("!Position report for %s! -by Ran"), *ObjectName);

	// ...
	
}


// Called every frame
void USecondPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

