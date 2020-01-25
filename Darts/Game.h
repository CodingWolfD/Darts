#pragma once

#include "Player.h"

class game
{
	public:
		void startRound(player* playerOne, int numOfRounds);
		void printEndOfGameStats();
		void enterPlayersPercentage(player* player);
		void startGame();
};

class gameVar
{
	public:
		int gameNum{ 0 };
		int menuChoice{ 0 };
};