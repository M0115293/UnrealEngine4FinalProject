// Fill out your copyright notice in the Description page of Project Settings.

#include "BallSpawnActor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Public/TimerManager.h"

// Sets default values
ABallSpawnActor::ABallSpawnActor()
{

}

// Called when the game starts or when spawned
void ABallSpawnActor::BeginPlay()
{
	//SpawnStart();
	Super::BeginPlay();
	
	
}

void ABallSpawnActor::SpawnObject()
{
	if (Ball != nullptr)
	{
		UWorld* const World = GetWorld();

		if (World)
		{
			AActor* const SpawnBall = World->SpawnActor<AActor>(Ball,SpawnLocation,FRotator(0.0f,0.0f,0.0f));
			//GetWorldTimerManager().SetTimer(SpawnTimer,this, &A)
		}
	}
}

void ABallSpawnActor::SpawnStart()
{
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ABallSpawnActor::SpawnObject, SpawnDelay, false);
}

