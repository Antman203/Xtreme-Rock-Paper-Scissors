#include "game.h"
#include "userType.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>

void game::boot()
{
	int w, l, t, t3, t5, t15;
	std::ifstream inObj;
	inObj.open("gameFile.txt");

	if (!inObj)
	{
		std::cout << "Could not find game file >> Program Terminates" << std::endl;
		system("pause");
		exit(0);
	}

	while (inObj.eof() == false)
	{
		inObj >> w >> l >> t >> t3 >> t5 >> t15;
	}

	user.statHandlerIn(w, l, t, t3, t5, t15);
	startMenu();
}

void game::startMatch(int play)
{
	user.go();
	computer.go();

	if (!isEqual())
	{
		if (deterWin() == 0)
			userPlay += 1;
		else
			comPlay += 1;
		printWin(deterWin());
		if (play != 1)
			startMatch(play - 1);
	}
	else
	{
		std::cout << "The Match is a Tie! Rematch!" << std::endl << std::endl;
		startMatch(play);
	}
}

void game::deterMatchWinner()
{
	std::cout << "      Player Points: " << userPlay << std::endl;
	std::cout << "         COM Points: " << comPlay << std::endl;
	std::cout << "The Match Winner is: ";
	if (userPlay > comPlay)
		std::cout << "Player!" << std::endl << std::endl << std::endl;
	else
		std::cout << "COM!" << std::endl << std::endl << std::endl;
	user.update(userPlay, comPlay, userPlay + comPlay);
	userPlay = 0;
	comPlay = 0;
	start();
}


void game::start(int safety)
{
	int sel;

	std::cout << "Make Selection: ";
	std::cin >> sel;

	switch (sel)
	{
	case 1:
	{
		displayRules();
		break;
	}
	case 2:
	{
		startMatch(3);
		user.updateGameData(3);
		deterMatchWinner();
		break;
	}
	case 3:
	{
		startMatch(5);
		user.updateGameData(5);
		deterMatchWinner();
		break;
	}
	case 4:
	{
		startMatch(15);
		user.updateGameData(15);
		deterMatchWinner();
		break;
	}
	case 5:
	{
		user.printStats();
		startMenu();
		break;
	}
	case 6:
		user.statHandlerOut();
	case 7:
		user.reset();
	default:
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Make a valid selection." << std::endl;
		if (safety < 5)
			start(safety + 1);
		else
			exit(0);
	}
	}
}

void game::displayRules()
{
	std::cout << "How to Play" << std::endl;
	std::cout << "1.  Player will go once per round." << std::endl;
	std::cout << "2.  The player and computer will choose Rock, Paper, or Scissors." << std::endl;
	std::cout << "3.  The game will determine who is the winner." << std::endl;
	std::cout << "4.  If there is a tie, their will be a rematch. There must be a winner." << std::endl;
	std::cout << "5.  The player can choose from three different game modes, Best of 3, Best of 5, and Best of 15." << std::endl;
	std::cout << "6.  Results are logged and can be viewed in statistics." << std::endl << std::endl;
	startMenu();
}

bool game::isEqual() const
{
	return (computer.getSelection() == user.getSelection());
}

int game::deterWin()
{
	if (computer.getSelection() == 'R' && user.getSelection() == 'P')
	{
		return 0;
	}
	else if (computer.getSelection() == 'P' && user.getSelection() == 'R')
	{
		return 1;
	}
	else if (computer.getSelection() == 'R' && user.getSelection() == 'S')
	{
		return 1;
	}
	else if (computer.getSelection() == 'S' && user.getSelection() == 'R')
	{
		return 0;
	}
	else if (computer.getSelection() == 'S' && user.getSelection() == 'P')
	{
		return 1;
	}
	else if (computer.getSelection() == 'P' && user.getSelection() == 'S')
	{
		return 0;
	}
}

void game::printWin(int winner) const
{
	if (winner == 0)
		std::cout << "Player Wins!" << std::endl;
	else
		std::cout << "COM Wins!" << std::endl;
}

void game::startMenu()
{
	std::cout << "Welcome to Xtreme Rock Paper Scissors!" << std::endl;
	std::cout << "Developed by Anthony Wright" << std::endl << std::endl;

	std::cout << "Enter numbers and press enter to follow the prompts to continue." << std::endl;
	std::cout << "1.  How to Play" << std::endl;
	std::cout << "2.  Best out of three match" << std::endl;
	std::cout << "3.  Best out of five match" << std::endl;
	std::cout << "4.  Best out of fifteen match" << std::endl;
	std::cout << "5.  Statistics" << std::endl;
	std::cout << "6.  Exit the program" << std::endl << std::endl;
	start();
}

game::game()
{
	userPlay = 0;
	comPlay = 0;
}