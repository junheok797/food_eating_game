#include "human.h"

Human::Human(int startX, int startY, int distance) : GameObject(startX, startY, distance)
{
	key = NULL;
}

void Human::move()
{
	switch (key)
	{
	case 'a':
		if (y - distance < 0) y = 20 + y - distance;
		else y -= distance;
		break;
	case 's':
		if (x + distance > 9) x = x + distance - 10;
		else x += distance;
		break;
	case 'd':
		if (x - distance < 0) x = 10 + x - distance;
		else x -= distance;
		break;
	case 'f':
		if (y + distance > 19) y = y + distance - 20;
		else y += distance;
		break;
	default:
		break;
	}
}

char Human::getShape()
{
	return 'H';
}

void Human::putkey(int key)
{
	this->key = key;
}