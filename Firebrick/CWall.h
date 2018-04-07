#ifndef INC_CARD_WALL
#define INC_CARD_WALL

#include "Game.h"
#include "CMinion.h"

/// <summary>
/// The wall class acts as a minion but must be targeted by enemies
/// </summary>
class CWall : public CMinion
{
public:
	/// <summary>
	/// Default minion constructor as the minion class takes no extra variables
	/// </summary>
	/// <param name="type">The ID of the card</param>
	/// <param name="">The name of the card</param>
	/// <param name="attack">The attack of the card</param>
	/// <param name="health">The health of the card</param>
	CWall(int type, std::string, int attack, int health);
};

#endif 