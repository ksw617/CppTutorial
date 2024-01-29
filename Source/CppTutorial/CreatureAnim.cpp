#include "CreatureAnim.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCreatureAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Character = Cast<ACharacter>(Pawn);
		if (IsValid(Character))
		{
			CharacterMovement = Character->GetCharacterMovement();
		}
	}
}

void UCreatureAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Character))
	{
		Velocity = CharacterMovement->Velocity;
		Speed = Velocity.Size2D();
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
