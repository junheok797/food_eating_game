#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <iostream>

enum directions { LEFT, DOWN, UP, RIGHT };

class GameObject
{
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance);
	virtual ~GameObject();

	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX();
	int getY();
	bool collide(GameObject& p);
};

#endif