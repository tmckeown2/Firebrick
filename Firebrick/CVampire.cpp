#include "CVampire.h"
#include <iostream>

using namespace std;

CVampire::CVampire(int type, string name, int attack, int health, int heals)
	: CMinion(type, name, attack, health)
{
	// Initialise the lifesteal
	mHeals = heals;
}

void CVampire::Attack(CPlayerPtr& opponent)
{
	// Standard minion attack
	CMinion::Attack(opponent);

	// Vampire heals after attacking
	this->Heal(mHeals);

	string name = this->GetName();
	int health = this->GetHealth();

	// Output the lifesteal
	cout << name << " heals for " << mHeals << ".";
	cout << name << " health now " << health << endl;
}