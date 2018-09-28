// Fill out your copyright notice in the Description page of Project Settings.

#include "PrositionReport.h"
#include <iostream>

// Sets default values for this component's properties
UPrositionReport::UPrositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPrositionReport::BeginPlay()
{
	Super::BeginPlay(); 

		UE_LOG(LogTemp, Warning, TEXT("!Position report reporting for duty on Chair! -by Ran"));

	// ...
	
}


// Called every frame
void UPrositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

