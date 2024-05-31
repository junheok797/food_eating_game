#ifndef MOSTER_H
#define	MONSTER_H
#include "game_object.h"

class Monster : public GameObject
{
public:
	Monster(int startX, int startY, int distance);
	void move();
	char getShape();
};

#endif