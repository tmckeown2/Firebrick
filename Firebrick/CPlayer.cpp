#include "Game.h"
#include "CPlayer.h"
#include <iostream>

using namespace std;

CPlayer::CPlayer(string name)
{
	// Set health and name
	mHealth = MAX_HEALTH;
	mName = name;
	isCardMinion = false;
}

int CPlayer::GetHealth() const
{
	// Gets current health
	return mHealth;
}

string CPlayer::GetName() const
{
	// Gets name
	return mName;
}

bool CPlayer::IsDead() const
{
	// Gets whether the player is dead or not
	return mHealth <= 0;
}

bool CPlayer::IsTableEmpty() const
{
	// Gets whether the table is empty or not
	return mpTable.size() == 0;
}

void CPlayer::Heal(int amount)
{
	// Increases health by an amount
	mHealth += amount;
}

void CPlayer::TakeDamage(int amount)
{
	// Reduces health by an amount
	mHealth -= amount;
}

void CPlayer::LoadDeck(string deckPath)
{
	// Create the deck and load in the cards
	mpDeck = make_unique<CDeck>(deckPath);

	// Shuffle the deck
	mpDeck->Shuffle();
	
	// Draw a starting card
	CCardPtr card = mpDeck->Draw();

	if (card == nullptr)
		return;

	cout << mName << " begins with " << card->GetName() << endl;
	mpHand.push_back(move(card));
}

void CPlayer::PlayTurn(CPlayerPtr& player, CPlayerPtr& opponent)
{
	// Draw a card
	CCardPtr card = mpDeck->Draw();

	if (card == nullptr)
		return;

	cout << mName << " draws " << card->GetName() << endl;
	mpHand.push_back(move(card));

	// Display hand
	DisplayHand();

	// Play a card from hand
	int random = (rand() % mpHand.size());
	mpHand[random]->Play(player, opponent);
	
	// If the card being played is a minion then cast and move to table
	if (isCardMinion)
	{
		// Cast the old card into a minion whilst preserving any underlying polymorphic changes to any "minions"
		CMinionPtr minion(dynamic_cast<CMinion*>(mpHand[random].release())); // Releasing the smart pointer from "mpHand" to avoid multiple owners of a unique_ptr
		mpTable.push_back(move(minion)); // Moving the minion from the temporary smart pointer object to the "mpTable" vector
		isCardMinion = false;
	}

	mpHand.erase(mpHand.begin() + random);

	// Check that the opponent is not dead before continuing
	if (!opponent->IsDead())
	{
		// Update table to remove any dead minions
		UpdateTable();

		// Display table
		DisplayTable();

		// Table attacks
		for (auto it = mpTable.begin(); it != mpTable.end(); ++it)
		{
			(*it)->Attack(opponent);
		}
	}
}

void CPlayer::DisplayHand()
{
	cout << "Hand: ";

	// Loop through hand and output the name of each card
	for (auto it = mpHand.begin(); it != mpHand.end(); ++it)
	{
		cout << (*it)->GetName() << " ";
	}

	cout << endl;
}

void CPlayer::DisplayTable()
{
	cout << "Table: ";

	// Loop through table and output the name and health of each card
	for (auto it = mpTable.begin(); it != mpTable.end(); ++it)
	{
		cout << (*it)->GetName() << "(" << (*it)->GetHealth() << ") ";
	}

	cout << endl;
}

void CPlayer::AddMinion()
{
	// Sets the next card to be placed onto the table
	isCardMinion = true;
}

void CPlayer::UpdateTable()
{
	bool minionKilled;

	// Loop through all minions on the table and remove the dead ones
	do
	{
		minionKilled = false;

		for (auto it = mpTable.begin(); it != mpTable.end(); ++it)
		{
			if ((*it)->GetHealth() <= 0)
			{
				// If a minion has negative or zero health then it must be removed
				mpTable.erase(it);
				minionKilled = true;

				// Break out of the loop to avoid errors with removing whilst iterating
				break; 
			}
		}

		// Loop until no dead minions are found
	} while (minionKilled);
}

CMinion* CPlayer::GetTableMinion()
{
	// If the table is empty do not return anything
	if (mpTable.size() == 0)
	{
		return nullptr;
	}

	// Loop through the table and check if there is a wall in play
	for (auto it = mpTable.begin(); it != mpTable.end(); ++it)
	{
		if ((*it)->GetType() == EWall)
		{
			// Return the raw pointer from the dereferenced iterator for the wall minion
			return (*it).get();
		}
	}

	// Return the raw pointer to avoid having to move the ownership of the smart pointer
	int random = (rand() % mpTable.size());
	return mpTable[random].get();
}

void CPlayer::DamageAllMinions(string cardName, int amount)
{
	// Loop through all minions on the table and damage them by an amount
	for (auto it = mpTable.begin(); it != mpTable.end(); ++it)
	{
		// Minion receives damage
		(*it)->TakeDamage(amount);

		// Output the name and health after taking damage
		string minionName = (*it)->GetName();
		int minionHealth = (*it)->GetHealth();

		cout << cardName << " attacks " << minionName << ".";

		// Check if the minion was killed and output current health or killed if the minion is dead
		if (minionHealth > 0)
		{
			cout << minionName << " health now " << minionHealth << endl;
		}
		else
		{
			cout << minionName << " killed" << endl;
		}
	}
}
