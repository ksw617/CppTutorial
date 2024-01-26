// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Creature.generated.h"

UCLASS()
class CPPTUTORIAL_API ACreature : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere)
	class UMyActorComponent* MyActorComponent;

public:
	// Sets default values for this character's properties
	ACreature() {}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
