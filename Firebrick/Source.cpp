#include <crtdbg.h>
#include <iostream>
#include "Game.h"
#include "CGameManager.h"

using namespace std;

void RunGame();

// TODO: Comment code

int main()
{
	cout << "Thomas McKeown Firebrick Assignment" << endl;

	// Run game loop in a separate function to avoid memory leaks being detected from variables that have not gone out of scope
	RunGame();

	// Pause and then check for memory leaks
	system("pause");
	_CrtDumpMemoryLeaks();
	return 0;
}

void RunGame()
{
	// Create the game manager class that will control all game functionality
	unique_ptr<CGameManager> pGameManager = make_unique<CGameManager>();

	// Seed the Random Number Generator
	pGameManager->SeedRNG("seed.txt"); 
	
	// Load the decks from text files into the player decks
	pGameManager->LoadDecks("sorceress.txt", "wizard.txt");
	
	// The game loops until over via rounds or player's dying
	while (!pGameManager->IsOver())
	{
		// The game manager will control both player's turns in the round
		pGameManager->PlayRound();
	}

	// Output the winner of the game
	pGameManager->DisplayWinner();
}