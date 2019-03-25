// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	APlayerHUD();

	

private:
	int Player1Point, Player2Point;

	int GetterPlayer1Point() { return Player1Point; }

	int GetterPlayer2Point() { return Player2Point; }

	void SetterPlayer1Point(int playerPoint) { Player1Point = playerPoint; };
	void SetterPlayer2Point(int playerPoint) { Player2Point = playerPoint; };
};
