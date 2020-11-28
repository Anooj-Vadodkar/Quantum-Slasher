#ifndef KNIGHT_H
#define KNIGHT_H
#include "Enemy.h"

class Knight: public Enemy{
    public:
        Knight(Sprite* idleSprite, Sprite* runSprite, Sprite* attackSprite, Hitbox* newHitbox, float x, float y, float w, float h, float spritew, float spriteh): 
        Enemy(idleSprite, runSprite, attackSprite, newHitbox, x, y, w, h, spritew, spriteh){};
        void draw();
        float getX();
        float getY();
        void moveToPlayer(float x, float y);
        void move(float, float);
};
#endif