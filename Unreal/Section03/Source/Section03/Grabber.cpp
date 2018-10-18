// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"
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

	FindPhysicsHandleComponent();

	SetupInputComponent();
}

void UGrabber::FindPhysicsHandleComponent()
{
	// find physics handle

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle)
	{

	}

	else

	{
		UE_LOG(LogTemp, Error, TEXT("No component found for %s"), *(GetWorld()->GetFirstPlayerController()->GetPawn()->GetName()))

	}

}

void UGrabber::SetupInputComponent()
{

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}

	else
	{
		UE_LOG(LogTemp, Error, TEXT("Input component found for %s"), *(GetWorld()->GetFirstPlayerController()->GetPawn()->GetName()));
	}
}


void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Grab key press"))

		auto HitResult = GetFirstPhysicBodyInReach();
	    auto ComponentToGrab = HitResult.GetComponent();
		auto ActorHit = HitResult.GetActor();

		if (!PhysicsHandle) { return; }
		if(ActorHit)
		{ 
			PhysicsHandle->GrabComponentAtLocation(
				ComponentToGrab,
				NAME_None,
				ComponentToGrab->GetOwner()->GetActorLocation()
			);
		}
}

void UGrabber::Release() {
	if (!PhysicsHandle) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Release key press"))
		PhysicsHandle->ReleaseComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) { return; }
	if (PhysicsHandle->GrabbedComponent)
	{
		 //move the object
		PhysicsHandle->SetTargetLocation(LineTraceEnd());
	}
}

FHitResult UGrabber::GetFirstPhysicBodyInReach() const
{
	/// set query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;


	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		LineTraceStart(),
		LineTraceEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	AActor* Actor = Hit.GetActor();

	if (Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Laser is pointing at: %s"), *(Actor->GetName()))
	}
	return Hit;
}

FVector UGrabber::LineTraceStart() const
{
	/// get palyer's view
	FVector PlayerPointLocation;
	FRotator PlayerPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT	PlayerPointLocation,
		OUT PlayerPointRotation
	);

	return PlayerPointLocation;
}

FVector UGrabber::LineTraceEnd() const
{
	/// get palyer's view
	FVector PlayerPointLocation;
	FRotator PlayerPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT	PlayerPointLocation,
		OUT PlayerPointRotation
	);

	return ( PlayerPointLocation + PlayerPointRotation.Vector()* Reach );
}