#ifndef KNIGHT_H
#define KNIGHT_H
#include "Enemy.h"

class Knight: public Enemy{
    public:
        Knight(Sprite* idleSprite, Sprite* runSprite, float x, float y, float w, float h, float spritew, float spriteh): 
        Enemy(idleSprite, runSprite, x, y, w, h, spritew, spriteh, 0.0008){};
        void moveToPlayer(float x, float y);
};
#endif