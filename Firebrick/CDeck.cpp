#include "Game.h"
#include "CDeck.h"
#include <fstream>
#include <sstream>
#include <algorithm>

#include "CMinion.h"
#include "CFireball.h"
#include "CLightning.h"
#include "CBless.h"
#include "CVampire.h"
#include "CWall.h"
#include "CHorde.h"
#include "CTrample.h"
#include "CLeech.h"
#include "CSword.h"
#include "CArmour.h"

using namespace std;

CDeck::CDeck()
{

}

CDeck::CDeck(string deckPath)
{
	// Load the cards from the text file at the path
	LoadDeck(deckPath);
}

void CDeck::LoadDeck(string deckPath)
{
	// Open the text file at the path
	ifstream infile(deckPath);

	// If the file is not found then exit the function to avoid errors
	if (!infile)
	{
		return;
	}

	// Read into a file line by line
	string line;
	while (getline(infile, line))
	{
		int type;
		istringstream ss(line);
		ss >> type;

		// Only push cards onto the deck that are implemented and in the enumerated type to avoid unknown errors
		if (0 < type && type <= EArmour)
		{
			mpCards.push_back(CardFactory(line));
		}
	}

	infile.close();
}

CCardPtr CDeck::Draw()
{
	// Only draw cards when the deck is not empty
	if (mpCards.empty())
	{
		return nullptr;
	}

	// Get the card from the queue and return it
	CCardPtr card = move(mpCards.front());
	mpCards.pop_front();
	return card;
}

void CDeck::Shuffle()
{
	// Shuffle only if there are cards in the container
	if (!mpCards.empty())
	{
		// Shuffle all cards in the deck
		random_shuffle(mpCards.begin(), mpCards.end());
	}
}

CCardPtr CDeck::CardFactory(std::string cardInfo)
{
	int type;
	string name;

	// Tokenise the card information
	istringstream ss(cardInfo);

	// Tokens placed into type and name
	ss >> type;
	ss >> name;

	// Extra tokens are based on type value
	switch (type)
	{
	case EMinion:
		// Minions attack and health are stored
		int minionAttack;
		int minionHealth;
		
		ss >> minionAttack;
		ss >> minionHealth;

		// Create a new CMinion object and return as a card
		return make_unique<CMinion>(type, name, minionAttack, minionHealth);
	case EFireball:
		// Fireball attack is stored
		int fireballAttack;

		ss >> fireballAttack;

		// Create a new CFireball object and return as card
		return make_unique<CFireball>(type, name, fireballAttack);
	case ELightning:
		// Lightning attack is stored
		int lightningAttack;

		ss >> lightningAttack;

		// Create a new CLightning object and return as card
		return make_unique<CLightning>(type, name, lightningAttack);
	case EBless:
		// Bless attack and heal
		int blessAttack;
		int blessHeal;

		ss >> blessAttack;
		ss >> blessHeal;

		// Create a new CBless object and return as card
		return make_unique<CBless>(type, name, blessAttack, blessHeal);
	case EVampire:
		// Vampire attack, health and lifesteal amount is stored
		int vampireAttack;
		int vampireHealth;
		int vampireHeals;

		ss >> vampireAttack;
		ss >> vampireHealth;
		ss >> vampireHeals;

		// Create a new CVampire object and return as card
		return make_unique<CVampire>(type, name, vampireAttack, vampireHealth, vampireHeals);
	case EWall:
		// Wall attack and health is stored
		int wallAttack;
		int wallHealth;

		ss >> wallAttack;
		ss >> wallHealth;

		// Create a new CWall object and return as card
		return make_unique<CWall>(type, name, wallAttack, wallHealth);
	case EHorde:
		// Horde attack, health and damage increment is stored
		int hordeAttack;
		int hordeHealth;
		int hordeAttackInc;

		ss >> hordeAttack;
		ss >> hordeHealth;
		ss >> hordeAttackInc;

		// Create a new CHorde object and return as card
		return make_unique<CHorde>(type, name, hordeAttack, hordeHealth, hordeAttackInc);
	case ETrample:
		// Trample attack and health is stored
		int trampleAttack;
		int trampleHealth;

		ss >> trampleAttack;
		ss >> trampleHealth;

		// Create a new CTrample object and return as card
		return make_unique<CTrample>(type, name, trampleAttack, trampleHealth);
	case ELeech:
		// Leech attack, health and lifesteal is stored
		int leechAttack;
		int leechHealth;
		int leechHeals;

		ss >> leechAttack;
		ss >> leechHealth;
		ss >> leechHeals;

		// Create a new CLeech object and return as card
		return make_unique<CLeech>(type, name, leechAttack, leechHealth, leechHeals);
	case ESword:
		// Sword attack increase is stored
		int swordAttackInc;

		ss >> swordAttackInc;

		// Create a new CSword object and return as card
		return make_unique<CSword>(type, name, swordAttackInc);
	case EArmour:
		// Armour protection is stored
		int armourProtection;

		ss >> armourProtection;

		// Create a new CArmour object and return as card
		return make_unique<CArmour>(type, name, armourProtection);
	default:
		// If the type is not recognised then null pointer is returned
		return nullptr;
	}
}