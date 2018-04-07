#ifndef INC_CARD_ARMOUR
#define INC_CARD_ARMOUR

#include "Game.h"
#include "CCard.h"

class CArmour : public CCard
{
private:
	int mProtection;	// The amount to increase damage mitigation (protection) by

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the protection.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="protection">The amount of protection.</param>
	CArmour(int type, std::string name, int protection);

	/// <summary>
	/// Targets a minion and increases the damage mitigation by an amount.
	/// Overrided CCard::Play function
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The player targeted by this card.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);

};

#endif