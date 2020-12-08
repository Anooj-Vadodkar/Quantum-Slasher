#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"
#include <vector>
class Player{
    int state = 0;
    Sprite* idleSprite;
    Sprite* runSprite;
    Sprite* attackSprite;
    std::vector<Sprite*> healthIndicator;
    bool isRight = true;
    const int MAX_HEALTH = 3;
    int health;
    int frame = 0;
    float w;
    float spritew;
    float h;
    float spriteh;
    float speed;
    float x;
    float y;
    public:
        Player(float w, float h, int spritew, int spriteh);
        void draw();
        void attack();
        bool playerRight();
        void flip();
        void move();
        void setState(int);
        int getState();
        bool damage();
        void addHealth();
        int getHealth();
};

#endif