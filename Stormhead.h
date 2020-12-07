#ifndef STORMHEAD_H
#define STORMHEAD_H
#include "Enemy.h"

class Stormhead: public Enemy{
    float num = 1;
    public:
        Stormhead(Sprite* idleSprite, Sprite* runSprite, float x, float y, float w, float h, float spritew, float spriteh): 
        Enemy(idleSprite, runSprite, x, y, w, h, spritew, spriteh, 0.001){};
        void moveToPlayer(float x, float y);
};

#endif