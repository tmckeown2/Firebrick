#ifndef INC_CARD_MINION
#define	INC_CARD_MINION

#include "Game.h"
#include "CCard.h"

class CMinion : public CCard
{
private:
	int mAttack;		// The amount of damage that the minion will deal when attacking.
	int mHealth;		// The amount of health that the minion currently has.
	int mProtection;	// The amount of damage mitigation the minion currently has.

public:
	/// <summary>
	/// The copy constructor for the CMinion class.
	/// </summary>
	/// <param name="copy">The CMinion object to copy data from.</param>
	CMinion(const CMinion* copy);

	/// <summary>
	/// The standard constructor for the CMinion class.
	/// </summary>
	/// <param name="type">The type value of the card.</param>
	/// <param name="name">The name of the card.</param>
	/// <param name="attack">The attack damage of the minion.</param>
	/// <param name="health">The health of the minion.</param>
	CMinion(int type, std::string name, int attack, int health);

	/// <summary>
	/// Getter for the attack damage.
	/// </summary>
	/// <returns>The attack damage.</returns>
	int GetAttack() const;

	/// <summary>
	/// Increases the attack damage by an amount.
	/// </summary>
	/// <param name="amount">The amount to increase the attack damage by.</param>
	void BuffAttack(int amount);

	/// <summary>
	/// Getter for the current health.
	/// </summary>
	/// <returns>The current health.</returns>
	int GetHealth() const;

	/// <summary>
	/// Heals the minion by an amount.
	/// </summary>
	/// <param name="amount">The amount to heal by.</param>
	void Heal(int amount);

	/// <summary>
	/// Reduces the minion's current health by an amount.
	/// </summary>
	/// <param name="amount">The amount of damage the minion will take.</param>
	void TakeDamage(int amount);

	/// <summary>
	/// Getter for the current damage mitigation.
	/// </summary>
	/// <returns>The damage mitigation.</returns>
	int GetProtection() const;

	/// <summary>
	/// Increases the damage mitigation by an amount.
	/// </summary>
	/// <param name="amount">The amount to increase the damage mitigation by.</param>
	void BuffProtection(int amount);

	/// <summary>
	/// Adds the minion to the caster's table.
	/// Overrided CCard::Play function.
	/// Overridable function.
	/// </summary>
	/// <param name="caster">The player that played the card.</param>
	/// <param name="opponent">The enemy player.</param>
	virtual void Play(CPlayerPtr& caster, CPlayerPtr& opponent);

	/// <summary>
	/// Targets an enemy minion, if there are any, otherwise targets the enemy player and damages them.
	/// Overridable function.
	/// </summary>
	/// <param name="opponent">The enemy player.</param>
	virtual void Attack(CPlayerPtr& opponent);
};

#endif 