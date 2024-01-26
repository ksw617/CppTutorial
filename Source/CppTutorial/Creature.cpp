// Fill out your copyright notice in the Description page of Project Settings.


#include "Creature.h"
#include "MyActorComponent.h"



// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	MyActorComponent = CreateDefaultSubobject<UMyActorComponent>(TEXT("MyActorComponent"));
	
}

