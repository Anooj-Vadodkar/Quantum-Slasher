#ifndef KNIGHT_H
#define KNIGHT_H
#include "Enemy.h"

class Knight: public Enemy{
    public:
        Knight(Sprite* idleSprite, Sprite* runSprite, Hitbox* newHitbox, float x, float y, float w, float h, float spritew, float spriteh): 
        Enemy(idleSprite, runSprite, newHitbox, x, y, w, h, spritew, spriteh, 0.0008){};
        void moveToPlayer(float x, float y);
        void move(float, float);
};
#endif