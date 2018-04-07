#include "Game.h"
#include "CCard.h"
#include <iostream>

using namespace std;

CCard::CCard(int type, string name)
{
	// Initialise the type and name of the card
	mType = type;
	mName = name;
}

int CCard::GetType() const
{
	// Returns the type
	return mType;
}

string CCard::GetName() const
{
	// Returns the name
	return mName;
}

void CCard::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	// Outputs the caster's name and the card name
	cout << caster->GetName() << " plays " << this->mName << endl;
}