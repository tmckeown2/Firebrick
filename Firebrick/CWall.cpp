#include "CWall.h"

using namespace std;

CWall::CWall(int type, string name, int attack, int health)
	: CMinion(type, name, attack, health)
{
	// Act as a minion
	// No extra features added in wall class, targeting is completed by the player
}