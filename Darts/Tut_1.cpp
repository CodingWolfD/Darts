#include "Player.h"

#include <cstdlib> 
#include <ctime>

player* joe = new player("Joe", 71);
player* sid = new player("Sid", 73);

int main()
{
	srand(time(NULL));
	joe->startGame(joe, 1);
	sid->startGame(sid, 1);
}