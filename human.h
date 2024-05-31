#ifndef HUMAN_H
#define HUMAN_H
#include <conio.h>
#include "game_object.h"

class Human : public GameObject
{
private:
	int key;
public:
	Human(int startX, int startY, int distance);
	void move();
	char getShape();
	void putkey(int key);
};

#endif