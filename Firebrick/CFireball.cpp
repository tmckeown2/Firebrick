#include "CFireball.h"
#include <iostream>

using namespace std;

CFireball::CFireball(int type, string name, int attack)
	: CCard(type, name)
{
	// Initialise the attack
	mAttack = attack;
}

void CFireball::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	bool noMinions = false;

	// Check if the enemy has any minions
	if (opponent->IsTableEmpty())
	{
		noMinions = true;
	}

	// 50:50 chance for attacking the opponent directly and attacking minions
	// Unless the opponent has no minions
	if (noMinions || rand() % 2)
	{
		// Attack the opponent directly
		opponent->TakeDamage(mAttack);

		string opponentName = opponent->GetName();
		int opponentHealth = opponent->GetHealth();

		// Output the card name and the target name
		cout << this->GetName() << " attacks " << opponentName << ". ";

		if (opponentHealth > 0)
		{
			// If the target survives then output remaining health
			cout << opponentName << " health now " << opponentHealth << endl;
		}
		else
		{
			// If the target dies then output killed message
			cout << opponentName << " killed" << endl;
		}
	}
	else
	{
		// Attack the opponent's minions
		CMinion* target = opponent->GetTableMinion();
		target->TakeDamage(mAttack);

		string targetName = target->GetName();
		int targetHealth = target->GetHealth();

		// Output card name and the target name
		cout << this->GetName() << " attacks " << targetName;

		if (targetHealth > 0)
		{
			// If the target survives then output remaining health
			cout << targetName << " health now " << targetHealth << endl;
		}
		else
		{
			// If the target dies then output killed message
			cout << targetName << " killed" << endl;
		}
	}
}