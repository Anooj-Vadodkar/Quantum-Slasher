#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include "Sprite.h"
#include <stdlib.h> 
class Level{
    int level;
    float x;
    float y;
    int frame;
    float portalX;
    float portalY;
    Sprite* levelOne;
    Sprite* portal;
    public:
        Level(int level){
            this->level = level;
            x = -4;
            y = 4;
            frame = 0;
            levelOne = new Sprite("Assets/LevelAssets/level1bg.png", 2, 2, x, y, 8, 8);
            srand(time(NULL));
            portalX = (rand()%40+1)/10;
            portalY = (rand()%40+1)/10;
            std::cout << portalX << " " << portalY << std::endl;
            portal = new Sprite("Assets/LevelAssets/portal.png", 1, 8, portalX-0.25, portalY+0.3, 0.5, 0.5);
        }
        void move(float deltax, float deltay){
            x += deltax;
            y += deltay;
            portalX += deltax;
            portalY += deltay;
            levelOne->move(deltax, deltay);
            portal->move(deltax, deltay);
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
        float getPortalX(){
            return portalX;
        }
        float getPortalY(){
            return portalY;
        }
        void draw(){
            frame++;
            levelOne->draw(0);
            if(frame == 24){
                portal->reset();
                frame = 0;
            }
            if(frame%3 == 0){
                portal->advance();
            }
            portal->draw(0.1);
        }
}; 

#endif