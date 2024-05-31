#include "monster.h"

Monster::Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance)
{
	srand((unsigned)time(0));
}

void Monster::move()
{
	int num;
	num = rand() % 2;
	switch (num)
	{
	case 0:
		if (x - distance < 0) x = 10 + x - distance;
		else x -= distance;
		break;
	case 1:
		if (x + distance > 9) x = x + distance - 10;
		else x += distance;
		break;
	}
	num = rand() % 2;
	switch (num)
	{
	case 0:
		if (y - distance < 0) y = 20 + y - distance;
		else y -= distance;
		break;
	case 1:
		if (y + distance > 19) y = y + distance - 20;
		else y += distance;
		break;
	}
}

char Monster::getShape()
{
	return 'M';
}