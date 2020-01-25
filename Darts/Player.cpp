#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// method used to generate a random number to determine if the player has hit the bulsseye or not
int player::generateRandomNum(player* player)
{
	player->random_num = rand() % 100 + 1;
	hitBullsEye(player->random_num, player);
	return player->random_num;
}

/*
method used to check if the random number generated is less than the players average
if so, return true and print out the required statement, else return false
*/
bool player::hitBullsEye(int& randomNum, player* player)
{
	if (randomNum <= player->percentage)
	{
		cout << "\n" << player->name << " has hit the bulls eye!";
		++player->num_of_throws;
		++player->num_of_bulls_hit;
		return true;
	}
	else
	{
		cout << "\n" << player->name << " has missed the bulls eye!";
		++player->num_of_throws;
		return false;
	}
}

double player::calculateAverage()
{
	average = ((double)totalHitsNeeded) / percentage * 100;
	return average;
}