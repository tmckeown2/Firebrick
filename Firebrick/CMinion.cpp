#include "Game.h"
#include "CMinion.h"
#include <iostream>

using namespace std;

CMinion::CMinion(const CMinion* copy)
	: CCard(copy->GetType(), copy->GetName())
{
	// Copies the attack, health and protection from the copy minion
	mAttack = copy->mAttack;
	mHealth = copy->mHealth;
	mProtection = copy->mProtection;
}

CMinion::CMinion(int type, string name, int attack, int health)
	: CCard(type, name)
{
	// Initialises the attack, health and protection
	mAttack = attack;
	mHealth = health;
	mProtection = 0;
}

int CMinion::GetAttack() const
{
	// Returns attack
	return mAttack;
}

void CMinion::BuffAttack(int amount)
{
	// Increases attack by an amount
	mAttack += amount;
}

int CMinion::GetHealth() const
{
	// Returns current health
	return mHealth;
}

void CMinion::Heal(int amount)
{
	// Increases health by an amount
	mHealth += amount;
}

void CMinion::TakeDamage(int amount)
{
	// Nothing will happen if protection of a minion is greater than the damage dealt to it
	if (mProtection < amount)
	{
		// Decreases the health by the damage after taking into consideration damage mitigation from protection
		mHealth -= (amount - mProtection);
	}
}

int CMinion::GetProtection() const
{
	// Returns the damage mitigation / protection
	return mProtection;
}

void CMinion::BuffProtection(int amount)
{
	// Increases the damage mitigation
	mProtection += amount;
}

void CMinion::Play(CPlayerPtr& caster, CPlayerPtr& opponent)
{
	// Call super class play function
	CCard::Play(caster, opponent);

	// Player is prompted to add this card to the table
	caster->AddMinion();
}

void CMinion::Attack(CPlayerPtr& opponent)
{
	// Do nothing if attack is less than zero
	if (this->mAttack <= 0)
		return;

	// Check if opponent has any minions
	if (opponent->IsTableEmpty())
	{
		// Attack opponent directly if no minions are on the table
		opponent->TakeDamage(this->mAttack);

		string name = opponent->GetName();
		int health = opponent->GetHealth();

		// Output the card name and target name
		cout << this->GetName() << " attacks " << name << ". ";
		
		if (health > 0)
		{
			// If target survives the attack output the health remaining
			cout << name << " health now " << health << endl;
		}
		else
		{
			// If target dies then output target killed
			cout << name << " killed" << endl;
		}
	}
	else
	{
		// Attack one of the opponent's minions
		CMinion* target = opponent->GetTableMinion();
		target->TakeDamage(this->mAttack);

		string targetName = target->GetName();
		int targetHealth = target->GetHealth();

		// Output the card name and target name
		cout << this->GetName() << " attacks " << targetName << ". ";

		if (targetHealth > 0)
		{
			// If target survives the attack output the health remaining
			cout << targetName << " health now " << targetHealth << endl;
		}
		else
		{
			// If target dies then output target killed
			cout << targetName << " killed" << endl;
		}

		// Opponent should now update table to remove any dead minions so they cannot be targeted again
		opponent->UpdateTable();
	}
}