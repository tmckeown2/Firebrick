#include "CLightning.h"
#include <iostream>

using namespace std;

CLightning::CLightning(int type, string name, int attack)
	: CCard(type, name)
{
	// Initialise the attack
	mAttack = attack;
}

void CLightning::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	// Damage all enemy minions
	opponent->DamageAllMinions(this->GetName(), mAttack);

	// Damage enemy directly
	opponent->TakeDamage(mAttack);

	string opponentName = opponent->GetName();
	int opponentHealth = opponent->GetHealth();

	// Output the card name and enemy name
	cout << this->GetName() << " attacks " << opponentName << ".";

	if (opponentHealth > 0)
	{
		// If the enemy survives then output remaining health
		cout << opponentName << " health now " << opponentHealth << endl;
	}
	else
	{
		// If the enemy dies then output killed message
		cout << opponentName << " killed" << endl;
	}
}