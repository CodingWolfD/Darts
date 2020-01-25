#pragma once
#include <string>

using namespace std;

class player
{
	public:
		int generateRandomNum(player* player);
		bool hitBullsEye(int& randomNum, player* player);
		double calculateAverage();

		string name{ "" };
		int percentage{ 0 };
		int num_of_throws{ 0 };
		int random_num{ 0 };
		int totalHitsNeeded{ 10 };
		int num_of_bulls_hit{ 0 };
		double average{ 0 };
		int gameNum{ 0 };

		player(string playerName, int playerPercentage)
		{
			name = playerName;
			percentage = playerPercentage;
		}

		~player() {}
};