#include "Player.h"
#include "Game.h"

#include <cstdlib> 
#include <ctime>
#include <iostream>

using namespace std;

// creates 2 new instances of the base player class, passing in a player name and average into the construtor
game Game;
gameVar* gameVariable = new gameVar();

player* joe = new player("Joe", 0);
player* sid = new player("Sid", 0);

int main()
{
	srand(time(NULL));

	Game.startGame();
	Game.printEndOfGameStats();
}

void game::startGame()
{
	Game.enterPlayersPercentage(joe);
	Game.enterPlayersPercentage(sid);

	if (joe->percentage > sid->percentage)
	{
		Game.startRound(joe, 1); // calls the Game.startGame method and passes in the player object and the number of rounds
		Game.startRound(sid, 1); // calls the Game.startGame method and passes in the player object and the number of rounds
	}
	else
	{
		Game.startRound(sid, 1); // calls the Game.startGame method and passes in the player object and the number of rounds
		Game.startRound(joe, 1); // calls the Game.startGame method and passes in the player object and the number of rounds
	}
}

void game::enterPlayersPercentage(player* player)
{
	cout << "\nPlease enter your chosen average bullseye hit for - " << player->name << "\n";
	cin >> player->percentage;
}

/*
method used to control the logic of the game, printing and displaying the required information to the user
*/
void game::startRound(player* player, int numOfRounds)
{
	cout << "\n\nPlayer Name: " << player->name;
	cout << "\nPlayers avergage bullseye hit: " << player->percentage << "%";

	cout << "\nPress any key to start simulation!";

	cin.get();

	// this do while loop controls the main logic for the application
	do
	{
		while (player->num_of_bulls_hit != player->totalHitsNeeded) // repeat code inside while the players number of bullseye hits are less than the required amount
		{
			cout << "\nDart has been thrown by " << player->name;
			player->generateRandomNum(player); // calls the players generateRandomNumber method and passes in the required player
		}

		cout << "\n\nRound " << gameVariable->gameNum + 1 << " finished";
		cout << "\n" << player->name << " took " << player->num_of_throws << " throws to hit 10 Bullseye";

		++gameVariable->gameNum; // increases the game number by 1, i used ++gameNum to avoid a copy of the variable being made and increased, therefore allows for a slightly faster program

		cin.get();

		player->num_of_bulls_hit = 0;
	} while (gameVariable->gameNum != numOfRounds);

	gameVariable->gameNum = 0;
}

/*
this method is responsible for displaying both players number of throws taken
to hit the bullseye 10 times. it then checks if the playerOne's amount of throws
is less than playerTwo's number of throws, if so print out playerOne's name and
their amount of throws. If not, print the same using playerTwo's information
*/
void game::printEndOfGameStats()
{
	cout << "\n\nPlayer 1 - " << joe->name << " number of throws - " << joe->num_of_throws;
	cout << "\nPlayer 2 - " << sid->name << " number of throws - " << sid->num_of_throws;

	cout << "\n" << joe->name << " average successful hits: " << joe->calculateAverage();
	cout << "\n" << sid->name << " average successful hits: " << sid->calculateAverage();

	if (joe->num_of_throws < sid->num_of_throws)
	{
		cout << "\nJoe wins with " << joe->num_of_throws;
	}
	else
	{
		cout << "\nSid wins with " << sid->num_of_throws;
	}

	cin.get();

	cout << "\n\nWould you like to run the simulation again? \n1) Start again \n2) Exit \n";
	cin >> gameVariable->menuChoice;

	switch (gameVariable->menuChoice)
	{
		case 1:
		{
			system("CLS");
			Game.startGame();
		}
			break;
		case 2:
		{
			exit(0);
		}
		break;
		default:
		{
			if (gameVariable->menuChoice != 1 || gameVariable->menuChoice != 2)
			{
				cout << "\n\nWould you like to run the simulation again?";
				cin >> gameVariable->menuChoice;
			}
		}
	}
}