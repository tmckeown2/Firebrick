#ifndef INC_CARD_BLESS
#define INC_CARD_BLESS

#include "Game.h"
#include "CCard.h"

class CBless : public CCard
{
private:
	int mAttack;	// Amount of damage to deal
	int mHeal;		// Amount of damage to heal

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the attack and heal amounts.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack.</param>
	/// <param name="heal">The heal.</param>
	CBless(int type, std::string name, int attack, int heal);

	/// <summary>
	/// Targets either enemy or player then chooses direct or minions. 
	/// Healing friendly minions or player and damaging enemy minions or player.
	/// Overrides CCard::Play function.
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The enemy player.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);
};

#endif 