#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include "Sprite.h"
#include <stdlib.h> 
class Level{
    int level;
    float x;
    float y;
    float portalX;
    float portalY;
    Sprite* levelOne;
    Sprite* portal;
    public:
        Level(int level){
            this->level = level;
            x = -4;
            y = 4;
            levelOne = new Sprite("Assets/LevelAssets/level1bg.png", 1, 1, x, y, 8, 8);
            srand(time(NULL));
            portalX = (rand()%300+100)/100.0;
            portalY = (rand()%300+100)/100.0;
            portal = new Sprite("Assets/LevelAssets/portal.png", 8, 1, portalX, portalY, 1, 1);
            std::cout << "portalX " << x << " portalY " << y; 
        }
        void move(float deltax, float deltay){
            x += deltax;
            y += deltay;
            levelOne->move(deltax, deltay);
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
        void draw(){
            levelOne->draw(0);
            portal->draw(0.1);
        }
}; 

#endif