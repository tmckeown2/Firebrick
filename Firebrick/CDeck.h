#ifndef INC_DECK
#define INC_DECK

#include "Game.h"
#include "CCard.h"

class CDeck
{
private:
	std::deque<CCardPtr> mpCards; // The container for cards. Using a double ended queue to allow for shuffling.

public:
	/// <summary>
	/// The default constructor for the CDeck class.
	/// </summary>
	CDeck();

	/// <summary>
	/// The constructor for the CDeck class.
	/// Loads cards into the deck using the text file.
	/// </summary>
	/// <param name="deckPath"></param>
	CDeck(std::string deckPath);

	/// <summary>
	/// Loads cards into the deck from a text file.
	/// </summary>
	/// <param name="deckPath">The path the text file.</param>
	void LoadDeck(std::string deckPath);

	/// <summary>
	/// Gets the next card in the deck.
	/// </summary>
	/// <returns>The next card in the deck.</returns>
	CCardPtr Draw();

	/// <summary>
	/// Shuffles the deck to be random.
	/// </summary>
	void Shuffle();

	/// <summary>
	/// Factory function that creates all types of card based on a single line of information from a text file.
	/// </summary>
	/// <param name="cardInfo">The information needed for the card.</param>
	/// <returns>The card created based on information.</returns>
	static CCardPtr CardFactory(std::string cardInfo);
};

#endif