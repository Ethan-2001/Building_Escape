#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How Far Ahead Of The Player Can We Reach In CM
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;
	
	// Ray-Cast Whats In Reach
	void Grab();
	
	// Called When Grab Is Released 
	void Release();

	// Find Attached Physics Handle
	void FindPhysicsHandleComponent();

	// Setup Assumed Input Component
	void SetupInputComponent();

	// Return Hit For First Physics Body In Reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
