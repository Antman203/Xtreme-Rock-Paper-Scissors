#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <iomanip>
#include "userType.h"
#include "game.h"

void userType::callSelectOp() const
{
	std::cout << "Enter numbers to enter the selections." << std::endl;
	std::cout << "1.  Rock" << std::endl;
	std::cout << "2.  Paper" << std::endl;
	std::cout << "3.  Scissors" << std::endl;
}

void userType::go(int safety)
{
	int sel;
	callSelectOp();
	std::cout << "Player: ";
	std::cin >> sel;

	switch (sel)
	{
	case 1:
	{
		selection = 'R';
		break;
	}
	case 2:
	{
		selection = 'P';
		break;
	}
	case 3:
	{
		selection = 'S';
		break;
	}
	default:
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Make a valid selection." << std::endl;
		if (safety < 5)
			go(safety + 1);
		else
			exit(0);
	}
	}
}

void userType::setSelection(int selection)
{
	this->selection = selection;
}

char userType::getSelection() const
{
	return selection;
}

void userType::updateGameData(int mode)
{
	if (mode == 3)
		total3Games += 1;
	else if (mode == 5)
		total5Games += 1;
	else if (mode == 15)
		total15Games += 1;
}

void userType::update(int w, int l, int t)
{
	wins = wins + w;
	losses = losses + l;
	totalGames = totalGames + t;
}

void userType::statHandlerIn(int w, int l, int t, int t3, int t5, int t15)
{
	wins = w;
	losses = l;
	totalGames = t;
	total3Games = t3;
	total5Games = t5;
	total15Games = t15;
}

void userType::statHandlerOut()
{
	std::fstream outObj;
	outObj.open("gameFile.txt");

	if (!outObj)
	{
		std::cout << "Could not find output file >> Program Terminates" << std::endl;
		system("pause");
		exit(0);
	}

	outObj << wins << '\n' << losses << '\n' << totalGames << '\n' << total3Games << '\n' << total5Games << '\n' << total15Games;
	exit(0);
}

void userType::printStats()
{
	std::cout << "          Total Wins:   " << wins << std::endl;
	std::cout << "        Total Losses:   " << losses << std::endl;
	std::cout << "         Total Games:   " << totalGames << std::endl;
	std::cout << " Total 3 Match Games:   " << total3Games << std::endl;
	std::cout << " Total 5 Match Games:   " << total5Games << std::endl;
	std::cout << "Total 15 Match Games:   " << total15Games << std::endl;
}

void userType::reset(int safety)
{
	int x;
	std::cout << "Are you sure you want to erase your save data? (It can never be recovered)" << std::endl;
	std::cout << "Enter 1 for Yes" << std::endl;
	std::cout << "Enter 2 for No" << std::endl;
	std::cout << "Selection: ";
	std::cin >> x;

	switch (x)
	{
	case 1:
	{
		wins = 0;
		losses = 0;
		totalGames = 0;
		total3Games = 0;
		total5Games = 0;
		total15Games = 0;
		break;
	}
	case 2:
		break;
	default:
	{
		std::cout << "Make a valid selection" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (safety < 5)
			reset(safety + 1);
		else
			exit(0);
	}
	}
}