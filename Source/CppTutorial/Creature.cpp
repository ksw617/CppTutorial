// Fill out your copyright notice in the Description page of Project Settings.


#include "Creature.h"
#include "MyActorComponent.h"
#include "CreatureAnim.h"



ACreature::ACreature()
{
	UE_LOG(LogTemp, Log, TEXT("ACreature"));
	MyActorComponent = CreateDefaultSubobject<UMyActorComponent>(TEXT("MyActorComponent"));
}

// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	CreatureAnimInstance = Cast<UCreatureAnim>(GetMesh()->GetAnimInstance());
	if (CreatureAnimInstance)
	{
		CreatureAnimInstance->OnMontageEnded.AddDynamic(this, &ACreature::OnAttackMontageEnded);
		CreatureAnimInstance->OnAttackHit.AddUObject(this, &ACreature::OnHit);
	}

}

void ACreature::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;
}

void ACreature::Attack()
{
	if (!IsAttacking)
	{
		IsAttacking = true;

		if (IsValid(CreatureAnimInstance))
		{
			CreatureAnimInstance->PlayAttackMontage();
		}

	}
}

void ACreature::OnHit()
{
	UE_LOG(LogTemp, Log, TEXT("On Hit"));
}

