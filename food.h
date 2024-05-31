#ifndef FOOD_H
#define FOOD_H
#include "game_object.h"

class Food : public GameObject
{
	int count;
public:
	Food(int startX, int startY, int distance);
	void move();
	char getShape();
};

#endif