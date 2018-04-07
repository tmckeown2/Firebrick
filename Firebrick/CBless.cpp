#include "CBless.h"
#include <iostream>

using namespace std;

CBless::CBless(int type, string name, int attack, int heal)
	: CCard(type, name)
{
	// Initialise attack and heal
	mAttack = attack;
	mHeal = heal;
}

void CBless::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	// Choose a target at random in order (e min, e player, f min, f player) with a 25% chance each
	bool enemyTarget = false;
	bool minionTarget = false;

	switch (rand() % 4)
	{
	case 0: // Enemy Minions
		enemyTarget = true;
		minionTarget = true;
		break;
	case 1: // Enemy Player
		enemyTarget = true;
		minionTarget = false;
		break;
	case 2: // Friendly Minions
		enemyTarget = false;
		minionTarget = true;
		break;
	case 3: // Friendly Player
		enemyTarget = false;
		minionTarget = false;
		break;
	}

	if (enemyTarget) // If the opponent was targeted
	{
		if (!minionTarget || opponent->IsTableEmpty()) // If the player was targeted or has no minions
		{
			opponent->TakeDamage(mAttack);

			string opponentName = opponent->GetName();
			int opponentHealth = opponent->GetHealth();

			// Output the card name and target name
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
		else // If the minions were targeted and the opponent has minions
		{
			CMinion* target = opponent->GetTableMinion();
			target->TakeDamage(mAttack);

			string targetName = target->GetName();
			int targetHealth = target->GetHealth();

			// Output the card name and target name
			cout << this->GetName() << " attacks " << targetName << ". ";

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
	else // If the caster was targeted
	{
		if (!minionTarget || caster->IsTableEmpty()) // If the player was targeted or has no minions
		{
			caster->Heal(mAttack);

			string casterName = caster->GetName();
			int casterHealth = caster->GetHealth();

			// Output the heal action
			cout << this->GetName() << " heals " << casterName << ". ";
			cout << casterName << " health now " << casterHealth << endl;
		}
		else // If the minions were targeted and the opponent has minions
		{
			CMinion* target = caster->GetTableMinion();
			target->Heal(mAttack);

			string targetName = target->GetName();
			int targetHealth = target->GetHealth();

			// Output the heal action
			cout << this->GetName() << " heals " << targetName << ". ";
			cout << targetName << " health now " << targetHealth << endl;
		}
	}
}