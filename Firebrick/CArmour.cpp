#include "CArmour.h"
#include <iostream>

using namespace std;

CArmour::CArmour(int type, string name, int protection)
	: CCard(type, name)
{
	// Initialise protection given
	mProtection = protection;
}

void CArmour::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	CCard::Play(caster, opponent);

	// If there are minions on the table then a minion will be selected and have protection increased by an amount
	if (!caster->IsTableEmpty())
	{
		// Get the target minion pointer and increase protection
		CMinion* target = caster->GetTableMinion();
		target->BuffProtection(mProtection);

		string targetName = target->GetName();
		int targetProtection = target->GetProtection();
		
		// Output the protection increase
		cout << this->GetName() << " buffs " << targetName << ". ";
		cout << targetName << " protection now " << targetProtection << endl;
	}
}