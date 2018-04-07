#ifndef INC_CARD
#define INC_CARD

#include "Game.h"

class CCard
{
private:
	int mType;			// Type of card
	std::string mName;  // Name of card

public:
	/// <summary>
	/// The constructor for the CCard class.
	/// Initialises the type and name of the card.
	/// </summary>
	/// <param name="type">The type of the card.</param>
	/// <param name="name">The name of the card.</param>
	CCard(int type, std::string name);

	/// <summary>
	/// Getter for the type.
	/// </summary>
	/// <returns>The type of card.</returns>
	int GetType() const;

	/// <summary>
	/// Getter for the name.
	/// </summary>
	/// <returns>The name of the card.</returns>
	std::string GetName() const;

	/// <summary>
	/// Outputs the caster's name and the card's name.
	/// Overridable.
	/// </summary>
	/// <param name="caster">The player that cast this card.</param>
	/// <param name="opponent">The player targeted by this card.</param>
	virtual void Play(CPlayerPtr& caster, CPlayerPtr& opponent);

};

#include "CPlayer.h"

#endif 