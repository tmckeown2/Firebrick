#include "CTrample.h"
#include <iostream>

using namespace std;

CTrample::CTrample(int type, string name, int attack, int health)
	: CMinion(type, name, attack, health)
{

}

void CTrample::Attack(CPlayerPtr& opponent)
{
	int damage = this->GetAttack();

	// Check if opponent has any minions
	if (opponent->IsTableEmpty())
	{
		// Attack opponent directly if no minions are on the table
		opponent->TakeDamage(damage);
	}
	else
	{
		// Loop until all damage has been used on targets
		while (damage > 0)
		{
			// Attack one of the opponent's minions
			CMinion* target = opponent->GetTableMinion();
			
			int targetCurrentHealth = target->GetHealth();

			target->TakeDamage(damage);

			string targetName = target->GetName();
			int targetHealth = target->GetHealth();

			cout << this->GetName() << " attacks " << targetName << ". ";

			if (targetHealth > 0)
			{
				cout << targetName << " health now " << targetHealth << endl;

				// If target isn't killed then there is no excess damage to be used again
				damage = 0;
			}
			else
			{
				cout << targetName << " killed" << endl;

				// Removes damage equal to the target's health - excess damage is then used in the next attack
				damage -= targetCurrentHealth;
			}

			// Opponent should now update table to remove any dead minions so they cannot be targeted again
			opponent->UpdateTable();
		}
	}
}