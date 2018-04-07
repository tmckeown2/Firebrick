#ifndef INC_CARD_LEECH
#define INC_CARD_LEECH

#include "Game.h"
#include "CMinion.h"

class CLeech : public CMinion
{
private:
	CPlayer* mpCaster;	// The player that cast this card
	int mHeals;			// The amount to lifesteal on an attack

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the lifesteal.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack of the minion.</param>
	/// <param name="health">The health of the minion.</param>
	/// <param name="heals">The lifesteal.</param>
	CLeech(int type, std::string name, int attack, int health, int heals);

	/// <summary>
	/// Stores a pointer to the casting player to be used later.
	/// Overrides CMinion::Play function
	/// </summary>
	/// <param name="caster">The player that cast the card.</param>
	/// <param name="opponent">The player targeted by the card.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);

	/// <summary>
	/// Attacks normally and heals the controlling player by an amount.
	/// Overrides CMinion::Attack function
	/// </summary>
	/// <param name="opponent">The enemy player.</param>
	void Attack(CPlayerPtr& opponent);
};

#endif