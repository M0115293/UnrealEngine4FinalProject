// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallSpawnActor.generated.h"

UCLASS()
class MYPROJECT_API ABallSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable ,  Category = "Ball")
	void SpawnObject();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
	FVector SpawnLocation;

	UFUNCTION(BlueprintCallable, Category = "Ball")
	//UFUNCTION( Server, Reliable, WithValidation)
	void SpawnStart();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
	TSubclassOf<class AActor> Ball;
	
	FTimerHandle SpawnTimer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball")
	float SpawnDelay;
};
