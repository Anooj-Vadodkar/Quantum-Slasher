#ifndef HITBOX_H
#define HITBOX_H

#include "Shape.h"

class Hitbox: public Shape{
protected:
	float x;
	float y;
	float w;
	float h;
	float a;

public:
	Hitbox(float, float, float, float);

	void move(float deltaX, float deltaY);
    void draw(float z) const;
    float getX();
    float getY();
    float getW();
    float getH();

	bool contains(Hitbox* otherHitbox);
    bool contains(float x, float y);
};

#endif