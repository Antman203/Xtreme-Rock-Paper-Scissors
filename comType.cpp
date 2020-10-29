#include <iostream>
#include <random>
#include "comType.h"
#include "userType.h"

void comType::go()
{
	int sel[3];
	std::random_device ranDev{};
	std::default_random_engine num{ ranDev() };
	std::uniform_int_distribution<unsigned int> randNum{ 1, 3 };

	for (int x = 0; x < 3; x++)
	{
		sel[x] = randNum(num);
		switch (sel[x])
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
		}
	}

	std::cout << "COM: " << selection << std::endl;
}

char comType::getSelection() const
{
	return selection;
}
