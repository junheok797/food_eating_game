#include "food.h"

Food::Food(int startX, int startY, int distance) : GameObject(startX, startY, distance)
{
	srand((unsigned)time(0));
	count = 0;
}

void Food::move()
{
	int n1, n2;		// n1 : 2/5 È®·ü, n2 : ¹æÇâ
	n1 = rand() % 5;
	n2 = rand() % 4;
	if (n1 >= 1 && n1 <= 2)
	{
		switch (n2)
		{
		case LEFT:
			if (y - distance < 0) y = 20 + y - distance;
			else y -= distance;
			break;
		case DOWN:
			if (x + distance > 9) x = x + distance - 10;
			else x += distance;
			break;
		case UP:
			if (x - distance < 0) x = 10 + x - distance;
			else x -= distance;
			break;
		case RIGHT:
			if (y + distance > 19) y = y + distance - 20;
			else y += distance;
			break;
		}
	}
}

char Food::getShape()
{
	return '@';
}