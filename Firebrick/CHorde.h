#ifndef INC_CARD_HORDE
#define INC_CARD_HORDE

#include "Game.h"
#include "CMinion.h"

class CHorde : public CMinion
{
private:
	static int mTrueAttack;	// The actual amount of damage that the minion does on attacking
	int mAttackInc;			// The amount to increase attack by per horde minion

public:
	/// <summary>
	/// Calls CCard constructor.
	/// Initialises the true attack and attack increase.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack of the minion.</param>
	/// <param name="health">The health of the minion.</param>
	/// <param name="attackInc">The attack increase per horde minion.</param>
	CHorde(int type, std::string name, int attack, int health, int attackInc);

	/// <summary>
	/// When a horde minion is deleted the true attack is reduced by an amount.
	/// </summary>
	~CHorde();

	/// <summary>
	/// Increases the true attack by an amount.
	/// Overrides CMinion::Play function.
	/// </summary>
	/// <param name="caster">The player that cast the card.</param>
	/// <param name="opponent">The player targeted by the card.</param>
	void Play(CPlayerPtr& caster, CPlayerPtr& opponent);

	/// <summary>
	/// Attacks using true attack rather than base attack.
	/// Overrides CMinion::Attack function.
	/// </summary>
	/// <param name="opponent">The enemy player.</param>
	void Attack(CPlayerPtr& opponent);
};

#endif 