// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManagerActor.generated.h"

UCLASS()
class MYPROJECT_API AGameManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGameManagerActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GoalPoint")
	int Player2Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GoalPoint")
	int Player1Point;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GoalPoint")
	int SetPoint;

public:	
	virtual void Tick(float DeltaTime) override;

	//TArray<AActor*> Managers;

	FORCEINLINE int GetterPlayer1Point() { return Player1Point; }

	FORCEINLINE int GetterPlayer2Point() { return Player2Point; }

	void SetterPlayer1Point(int playerPoint) { Player1Point = playerPoint; };
	void SetterPlayer2Point(int playerPoint) { Player2Point = playerPoint; };

private:
	
	
	

};
