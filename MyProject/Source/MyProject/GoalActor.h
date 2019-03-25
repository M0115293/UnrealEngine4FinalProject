// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoalActor.generated.h"
//#include "PlayerHUD.h"

class UBoxComponent;

UCLASS()
class MYPROJECT_API AGoalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UBoxComponent* CollisionComp;

	//APlayerHUD* const scoreManager = Cast<APlayerHUD>(scoreManager);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	int GoalNumber;

	UFUNCTION()
		void Goal(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
