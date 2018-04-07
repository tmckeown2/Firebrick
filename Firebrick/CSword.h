#ifndef INC_CARD_SWORD
#define INC_CARD_SWORD

#include "Game.h"
#include "CCard.h"

class CSword : public CCard
{
private:
	int mAttackInc;	// The amount to increase attack by

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the attack increase.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attackInc">The amount to increase attack by.</param>
	CSword(int type, std::string name, int attackInc);

	/// <summary>
	/// Picks a target and increases the attack of a minion or heals the player by an amount.
	/// Overrided CCard::Play function
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The player targeted by this card.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);
};

#endif 