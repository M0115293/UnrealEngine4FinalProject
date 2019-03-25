// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalActor.h"
#include "Components/BoxComponent.h"
//#include "ScoreManager.h"

// Sets default values
AGoalActor::AGoalActor()
{
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	CollisionComp->InitBoxExtent(FVector(5.0f,5.0f,5.0f));
	CollisionComp->OnComponentHit.AddDynamic(this, &AGoalActor::Goal);

	RootComponent = CollisionComp;

}

// Called when the game starts or when spawned
void AGoalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGoalActor::Goal(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		UE_LOG(LogTemp, Error,	TEXT("HIT"));
		OtherComp->AddImpulseAtLocation(FVector(1.0f,1.0f,1.0f) * 1000.0f, GetActorLocation());

	}
}

