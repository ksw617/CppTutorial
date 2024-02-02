#include "CreatureAnim.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Creature.h"

void UCreatureAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Character = Cast<ACreature>(Pawn);
		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
		}
	}

	OnDeath = false;
}

void UCreatureAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Character))
	{
		Velocity = CharacterMovement->Velocity;
		Speed = Velocity.Size2D();

		if (Character->GetHp() <= 0 && !OnDeath)
		{
			OnDeath = true;
		}
	}
}

void UCreatureAnim::PlayAttackMontage()
{
	if (IsValid(AttackMontage))
	{
		if (!Montage_IsPlaying(AttackMontage))
		{
			Montage_Play(AttackMontage);
		}
	}
}

void UCreatureAnim::AnimNotify_Hit()
{
	OnAttackHit.Broadcast();
}
