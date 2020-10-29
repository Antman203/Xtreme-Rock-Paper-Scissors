#ifndef GAME_H
#define GAME_H
#include "comType.h"
#include "userType.h"

class game
{
public:
	game();
	void boot();
	void startMatch(int);
	void start(int = 0);
	void startMenu();
	void displayRules();
	bool isEqual() const;
	int deterWin();
	void deterMatchWinner();
	void printWin(int) const;
private:
	comType computer;
	userType user;
	int userPlay;
	int comPlay;
};

#endif