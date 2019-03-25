// Fill out your copyright notice in the Description page of Project Settings.

#include "GoalActorSphere.h"
#include "Components/SphereComponent.h"
#include "GameManagerActor.h"
#include "BallSpawnActor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AGoalActorSphere::AGoalActorSphere()
{
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	//CollisionComp->OnComponentHit.AddDynamic(this, &AGoalActorSphere::GoalAction);

	PrimaryActorTick.bCanEverTick = true;



}

void AGoalActorSphere::BeginPlay()
{
	Super::BeginPlay();

	//TSubclassOf<ABallSpawnActor> findclass02;
	//findclass02 = ABallSpawnActor::StaticClass();
	//TArray<AActor*> Managers;
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), findclass02, BallSpawner);

	TSubclassOf<AGameManagerActor> findclass;
	findclass = AGameManagerActor::StaticClass();
	//TArray<AActor*> Managers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), findclass, Managers);
}

void AGoalActorSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
void AGoalActorSphere::GoalAction(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		UE_LOG(LogTemp, Error, TEXT("HIT"));
		OtherActor->Destroy();

		if (GoalNumber == 0)
		{
			AGameManagerActor *  gameMangaer = Cast<AGameManagerActor>(Managers[0]);
			gameMangaer->SetterPlayer1Point(gameMangaer->GetterPlayer1Point() + 1);

		}
		if (GoalNumber == 1)
		{
			AGameManagerActor *  gameMangaer = Cast<AGameManagerActor>(Managers[0]);
			gameMangaer->SetterPlayer2Point(gameMangaer->GetterPlayer2Point() +  1);
		}

		//ABallSpawnActor * ballManager = Cast<ABallSpawnActor>(BallSpawner[0]);
		//ballManager->SpawnStart();

	}
}*/

