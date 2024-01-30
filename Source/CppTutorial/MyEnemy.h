// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Creature.h"
#include "MyEnemy.generated.h"

UCLASS()
class CPPTUTORIAL_API AMyEnemy : public ACreature
{
	GENERATED_BODY()

public:
	bool GetIsAttacking() const { return IsAttacking; }
public:
	AMyEnemy();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	virtual void OnHit() override;
};
