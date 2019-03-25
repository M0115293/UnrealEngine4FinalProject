// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoalActorSphere.generated.h"
//#include "GameManagerActor.h"

class USphereComponent;

UCLASS()
class MYPROJECT_API AGoalActorSphere : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalActorSphere();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GoalPoint")
	int Player2Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GoalPoint")
	int Player1Point;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* CollisionComp;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Goal")
	int GoalNumber;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Goal")
	//class BallSpawnActor*  BallSpawn;

	TArray<AActor*> Managers;

	TArray<AActor*> BallSpawner;

	//AGameManagerActor *  gameMangaer = Cast<AGameManagerActor>(GameManager);

	//UFUNCTION()
	//void GoalAction(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


};
