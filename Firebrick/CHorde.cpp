#include "CHorde.h"
#include <iostream>

using namespace std;

// Defining the static variable
int CHorde::mTrueAttack;

CHorde::CHorde(int type, string name, int attack, int health, int attackInc)
	: CMinion(type, name, attack, health)
{
	// Initialise the attack increment per horde minion
	mAttackInc = attackInc;
}

CHorde::~CHorde()
{
	// When a rat is removed the true damage is lowered by mAttackInc
	mTrueAttack -= mAttackInc;
}

void CHorde::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	// Default play function
	CMinion::Play(caster, opponent);

	// Increment damage for all rats
	mTrueAttack += mAttackInc;
}

void CHorde::Attack(CPlayerPtr& opponent)
{
	// Rat uses true attack rather than base attack and should use the modified attack function

	// Check if opponent has any minions
	if (opponent->IsTableEmpty())
	{
		// Attack opponent directly if no minions are on the table
		opponent->TakeDamage(this->mTrueAttack);
	}
	else
	{
		// Attack one of the opponent's minions
		CMinion* target = opponent->GetTableMinion();
		target->TakeDamage(this->mTrueAttack);

		string targetName = target->GetName();
		int targetHealth = target->GetHealth();

		// Output the card name and target name
		cout << this->GetName() << " attacks " << targetName << ". ";

		if (targetHealth > 0)
		{
			// If target survives then output the remaining health
			cout << targetName << " health now " << targetHealth << endl;
		}
		else
		{
			// If the target is killed then output killed message
			cout << targetName << " killed" << endl;
		}

		// Opponent should now update table to remove any dead minions so they cannot be targeted again
		opponent->UpdateTable();
	}
}