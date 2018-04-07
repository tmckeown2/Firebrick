#ifndef INC_CARD_TRAMPLE
#define INC_CARD_TRAMPLE

#include "Game.h"
#include "CMinion.h"

class CTrample : public CMinion
{
private:

public:
	/// <summary>
	/// Calls CCard constructor.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack of the minion.</param>
	/// <param name="health">The health of the minion.</param>
	CTrample(int type, std::string name, int attack, int health);

	/// <summary>
	/// Attacks targets until no excess damage is remaining.
	/// Overrides CMinion::Attack function.
	/// </summary>
	/// <param name="opponent">The target player.</param>
	void Attack(CPlayerPtr& opponent);
};

#endif 