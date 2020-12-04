#ifndef DRONE_H
#define DRONE_H
#include "Enemy.h"
class Drone: public Enemy{
    float degree = 0;
    public: 
        Drone(Sprite* idleSprite, Sprite* runSprite, Hitbox* newHitbox, float x, float y, float w, float h, float spritew, float spriteh): 
        Enemy(idleSprite, runSprite, newHitbox, x, y, w, h, spritew, spriteh, 0.002){};
        void moveToPlayer(float x, float y);
};

#endif