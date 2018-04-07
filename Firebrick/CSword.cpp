#include "CSword.h"
#include <iostream>

using namespace std;

CSword::CSword(int type, string name, int attackInc)
	: CCard(type, name)
{
	// Initialise attack increase
	mAttackInc = attackInc;
}

void CSword::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	CCard::Play(caster, opponent);

	if (caster->IsTableEmpty())
	{
		// If there are no friendly minions then the sword will increase player health
		caster->Heal(mAttackInc);

		string name = caster->GetName();
		int health = caster->GetHealth();

		// Output the heal action
		cout << this->GetName() << " heals " << name << ". ";
		cout << name << " health now " << health << endl;
	}
	else
	{
		// If there are friendly minions then the sword will increase the damage of one
		CMinion* target = caster->GetTableMinion();
		target->BuffAttack(mAttackInc);

		string targetName = target->GetName();
		int targetAttack = target->GetAttack();

		// Output the attack increase action
		cout << this->GetName() << " buffs " << targetName << ". ";
		cout << targetName << " attack now " << targetAttack << endl;
	}

}