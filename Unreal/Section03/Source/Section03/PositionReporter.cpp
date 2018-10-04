// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReporter.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UPositionReporter::UPositionReporter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UPositionReporter::BeginPlay()
{
	Super::BeginPlay();
	
	FString ObjectName = GetOwner()->GetName();
	//FString ObjectPos = "X= something, Y = something, etc??";
	FString ObjectPos_X = FString::SanitizeFloat(GetOwner()->GetActorLocation().X);
	FString ObjectPos_Y = FString::SanitizeFloat(GetOwner()->GetActorLocation().Y);
	FString ObjectPos_Z = FString::SanitizeFloat(GetOwner()->GetActorLocation().Z);

	UE_LOG(LogTemp, Warning, TEXT("%s is at (%s,%s,%s)"), *ObjectName, *ObjectPos_X, *ObjectPos_Y, *ObjectPos_Z);
	// ...
	
}
 

// Called every frame
void UPositionReporter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

