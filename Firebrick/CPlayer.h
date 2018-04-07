#ifndef INC_PLAYER
#define INC_PLAYER

#include "Game.h"
#include "CDeck.h"
#include "CMinion.h"

class CPlayer
{
private:
	static const int MAX_HEALTH = 30;	// The maximum health for the player.
	int mHealth;						// The current health for the player.
	std::string mName;					// The name for the player.

	CDeckPtr mpDeck;					// The deck  for the player - Holds all cards.
	std::vector<CCardPtr> mpHand;		// The hand	 for the player - Holds cards once drawn.
	std::vector<CMinionPtr> mpTable;	// The table for the player - Holds minions that have been played.

	bool isCardMinion;					// Used to check if a card that was played is a minion or not.

public:
	/// <summary>
	/// The constructor for the CPlayer class.
	/// Sets the health to max and sets the name.
	/// </summary>
	/// <param name="name">The name to set for the player.</param>
	CPlayer(std::string name);

	/// <summary>
	/// Getter for the player name.
	/// </summary>
	/// <returns>The player name.</returns>
	std::string GetName() const;

	/// <summary>
	/// Getter for the player health.
	/// </summary>
	/// <returns>The player's current health.</returns>
	int GetHealth() const;

	/// <summary>
	/// Checks if the player has zero or negative health and is dead.
	/// </summary>
	/// <returns>True if the player health is less than or equal to zero. Otherwise, false.</returns>
	bool IsDead() const;

	/// <summary>
	/// Checks if there are minions on the player's table.
	/// Used to check if a minion should target the opponent's minions or directly.
	/// </summary>
	/// <returns>True if the table container is empty. Otherwise, false.</returns>
	bool IsTableEmpty() const;

	/// <summary>
	/// Heals the player by an amount.
	/// The health may surpass the maximum starting health.
	/// </summary>
	/// <param name="amount">The amount to heal.</param>
	void Heal(int amount);

	/// <summary>
	/// Damages the player by an amount.
	/// The health may drop below zero but will not be able to play their turn.
	/// </summary>
	/// <param name="amount">The amount of damage to take.</param>
	void TakeDamage(int amount);

	/// <summary>
	/// Loads cards into the player's deck.
	/// </summary>
	/// <param name="deckPath"></param>
	void LoadDeck(std::string deckPath);

	/// <summary>
	/// Plays the player's turn.
	/// Draws a card from the deck into the hand.
	/// Plays a card at random from the hand.
	/// Minions on the table then attack.
	/// </summary>
	/// <param name="player">The current player.</param>
	/// <param name="opponent">The enemy player.</param>
	void PlayTurn(CPlayerPtr& player, CPlayerPtr& opponent);

	/// <summary>
	/// Displays the contents of the player's hand using stdio.
	/// </summary>
	void DisplayHand();

	/// <summary>
	/// Displays the contents of the player's table using stdio.
	/// </summary>
	void DisplayTable();

	/// <summary>
	/// Sets the card being played to be put onto the table.
	/// </summary>
	void AddMinion();

	/// <summary>
	/// Checks all minions on the table and deletes the card if it has been killed (has less than or equal to zero health).
	/// </summary>
	void UpdateTable();

	/// <summary>
	/// Gets a random minion from the table.
	/// </summary>
	/// <returns>The pointer to the minion object.</returns>
	CMinion* GetTableMinion();

	/// <summary>
	/// Damages all minions on the table by an amount.
	/// </summary>
	/// <param name="cardName">The name of the card doing damage to all minions. Used to output what deals the damage to minions.</param>
	/// <param name="amount">The amount of damage being done to all minions.</param>
	void DamageAllMinions(std::string cardName, int amount);
};

#endif 