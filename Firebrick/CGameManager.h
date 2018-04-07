#ifndef INC_GAME_MANAGER
#define INC_GAME_MANAGER

#include "Game.h"
#include "CPlayer.h"

class CGameManager
{
private:
	static const int MAX_ROUNDS = 30;	// The maximum number of rounds in the game
	int mRounds;						// The current number of rounds in the game

	CPlayerPtr mpSorceress;				// The sorceress player object
	CPlayerPtr mpWizard;				// The wizard    player object

public:
	/// <summary>
	/// The constructor for the CGameManager class.
	/// Creates the two player objects and initialises them.
	/// </summary>
	CGameManager();

	/// <summary>
	/// Seeds the random number generator that will be used throughout the program.
	/// </summary>
	/// <param name="seedFile">The file from which the seed is read.</param>
	void SeedRNG(std::string seedFile);

	/// <summary>
	/// Checks if the game is over or not.
	/// </summary>
	/// <returns>True if the rounds are at maximum or if either of the players are dead. Otherwise, false.</returns>
	bool IsOver();

	/// <summary>
	/// Outputs the winner (Sorceress or Wizard) or draw, depending on the outcome of the game, using stdio.
	/// </summary>
	void DisplayWinner();

	/// <summary>
	/// Loads the decks from text files into the player's decks.
	/// </summary>
	/// <param name="sorceressDeck">The file from which the deck list is read for the Sorceress.</param>
	/// <param name="wizardDeck">The file from which the deck list is read for the Wizard.</param>
	void LoadDecks(std::string sorceressDeck, std::string wizardDeck);

	/// <summary>
	/// Plays each player's turn and increments the round count.
	/// </summary>
	void PlayRound();
};

#endif 