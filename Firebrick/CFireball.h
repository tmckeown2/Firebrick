#ifndef INC_CARD_FIREBALL
#define INC_CARD_FIREBALL

#include "Game.h"
#include "CCard.h"

class CFireball : public CCard
{
private:
	int mAttack;	// The amount of damage to deal

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the attack damage.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack damage.</param>
	CFireball(int type, std::string name, int attack);

	/// <summary>
	/// Targets a random enemy (minion or player) and damages them for an amount.
	/// Overrides CCard::Play function.
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The enemy player.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);
};

#endif 