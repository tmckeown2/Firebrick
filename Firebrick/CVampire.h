#ifndef INC_CARD_VAMPIRE
#define INC_CARD_VAMPIRE

#include "Game.h"
#include "CMinion.h"

class CVampire : public CMinion
{
private:
	int mHeals;	// The amount to heal by each attack

public:
	/// <summary>
	/// Initialises the amount of lifesteal.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack of the minion.</param>
	/// <param name="health">The health of the minion.</param>
	/// <param name="heals">The lifesteal.</param>
	CVampire(int type, std::string name, int attack, int health, int heals);

	/// <summary>
	/// Attacks normally and heals itself by an amount.
	/// Overrided CMinion::Attack function.
	/// </summary>
	/// <param name="opponent"></param>
	void Attack(CPlayerPtr& opponent);
};


#endif 