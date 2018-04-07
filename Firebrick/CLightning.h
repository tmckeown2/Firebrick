#ifndef INC_CARD_LIGHTNING
#define INC_CARD_LIGHTNING

#include "Game.h"
#include "CCard.h"

class CLightning : public CCard
{
private:
	int mAttack;	// The amount of attack damage

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the attack damage.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack damage.</param>
	CLightning(int type, std::string name, int attack);

	/// <summary>
	/// Damages all enemy minions and the enemy player by an amount.
	/// Overrides CCard::Play function.
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The enemy player.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);
};

#endif