// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"

UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true; //   InitializeComponent 호출 가능
	Level = 1;

}

void UMyActorComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetLevel(Level);
}

void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("ActorComponent"));
}

void UMyActorComponent::SetLevel(int32 Lv)
{
	//Todo
}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	//Todo
}

