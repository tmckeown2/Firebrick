#ifndef INC_GAME
#define INC_GAME

#include <string>
#include <queue>
#include <vector>
#include <memory>

// Forward declarations used to create the type definitions.
class CGameManager;
class CPlayer;
class CDeck;
class CCard;
class CMinion;

// Type definitions for the smart pointers.
typedef std::unique_ptr<CGameManager> CGameManagerPtr;
typedef std::unique_ptr<CPlayer> CPlayerPtr;
typedef std::unique_ptr<CDeck> CDeckPtr;
typedef std::unique_ptr<CCard> CCardPtr;
typedef std::unique_ptr<CMinion> CMinionPtr;

// Enumerated type to store the types of cards in the game.
enum ECardType
{
	ENullCard,
	EMinion,
	EFireball, 
	ELightning, 
	EBless, 
	EVampire, 
	EWall, 
	EHorde, 
	ETrample,  
	ELeech, 
	ESword, 
	EArmour 
};

#endif