#include "Game.h"
#include "CGameManager.h"
#include <iostream>
#include <fstream>

using namespace std;

CGameManager::CGameManager()
{
	// Initialises the rounds
	mRounds = 0;

	// Creates the sorceress and wizard players
	mpSorceress = make_unique<CPlayer>("Sorceress");
	mpWizard = make_unique<CPlayer>("Wizard");
}

void CGameManager::SeedRNG(string seedFile)
{
	// Read in the seed from the text file
	int seed;
	ifstream infile("seed.txt");
	infile >> seed;
	infile.close();

	// Seed the RNG
	srand(seed);
}

bool CGameManager::IsOver()
{
	// Check if either player is dead
	bool playersDead = mpSorceress->IsDead() || mpWizard->IsDead();

	// Check if the rounds have reached the limit
	bool roundsOver = mRounds >= MAX_ROUNDS;

	// Return true if either are true. Otherwise, false.
	return playersDead || roundsOver;
}

void CGameManager::DisplayWinner()
{
	// Check if players are dead and if the rounds are at the limit
	bool sorceressDead = mpSorceress->IsDead();
	bool wizardDead = mpWizard->IsDead();
	bool maxRoundsReached = mRounds >= MAX_ROUNDS;

	if (sorceressDead && !wizardDead)
	{
		// If the sorceress is dead but the wizard isn't then wizard wins
		cout << "Wizard wins!" << endl;
	}
	else if (wizardDead && !sorceressDead)
	{
		// If the wizard is dead but the sorceress isn't then sorceress wins
		cout << "Sorceress wins!" << endl;
	}
	else if (maxRoundsReached)
	{
		// If the rounds are at the limit then the game ends in a draw
		cout << "Draw!" << endl;
	}
}

void CGameManager::LoadDecks(std::string sorceressDeck, std::string wizardDeck)
{
	// Load both player's decks from the text files at each path
	mpSorceress->LoadDeck(sorceressDeck);
	mpWizard->LoadDeck(wizardDeck);
}

void CGameManager::PlayRound()
{
	// If the rounds are not at the limit then play the round
	if (mRounds < MAX_ROUNDS)
	{
		// Output the round number
		cout << endl << "Round " << ++mRounds << endl;

		// If sorceress isn't dead then sorceress plays the turn
		if (!mpSorceress->IsDead())
		{
			mpSorceress->PlayTurn(mpSorceress, mpWizard);
		}

		cout << endl;

		// If wizard isn't dead then wizard plays the turn
		if (!mpWizard->IsDead())
		{
			mpWizard->PlayTurn(mpWizard, mpSorceress);
		}
	}
}