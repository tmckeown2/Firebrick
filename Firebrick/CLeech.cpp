#include "CLeech.h"
#include <iostream>

using namespace std;

CLeech::CLeech(int type, string name, int attack, int health, int heals)
	: CMinion(type, name, attack, health)
{
	mHeals = heals;
}

void CLeech::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	CMinion::Play(caster, opponent);

	// Store the raw pointer to the caster in order to heal when minion attacks
	mpCaster = caster.get();
}

void CLeech::Attack(CPlayerPtr& opponent)
{
	// Call superclass attack function to attack normally
	CMinion::Attack(opponent);

	// Heal the player that owns this minion
	mpCaster->Heal(mHeals);

	string name = mpCaster->GetName();
	int health = mpCaster->GetHealth();

	// Output the healing
	cout << this->GetName() << " heals " << name << ". ";
	cout << name << " health now " << health << endl;
}