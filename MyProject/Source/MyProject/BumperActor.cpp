// Fill out your copyright notice in the Description page of Project Settings.

#include "BumperActor.h"
#include "Components/SphereComponent.h"




// Sets default values
ABumperActor::ABumperActor()
{
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	//CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ABumperActor::BumperAction);

	RootComponent = CollisionComp;
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABumperActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABumperActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABumperActor::BumperAction(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		UE_LOG(LogTemp, Error,	TEXT("HIT"));
		OtherComp->AddImpulseAtLocation(FVector(1.0f,1.0f,1.0f) * 1000.0f, GetActorLocation());

	}
}

