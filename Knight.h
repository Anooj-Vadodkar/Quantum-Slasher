#ifndef KNIGHT_H
#define KNIGHT_H
#include "Enemy.h"

class Knight: public Enemy{
    public:
        Knight(Sprite* idleSprite, Sprite* runSprite, Sprite* attackSprite, Hitbox* newHitbox, float x, float y, float w, float h): 
        Enemy(idleSprite, runSprite, attackSprite, newHitbox, x, y, w, h){};
        void draw();
        float getX();
        float getY();
        void moveToPlayer();
        void move(float, float);
};
#endif