#include <iostream>
#include "Knight.h"
#include <cmath>

float Knight::getX(){
    return x;
}

float Knight::getY(){
    return y;
}
void Knight::moveToPlayer(float x, float y){
    // This is the basic function that defines how the knight class enemy interacts with the player;
    // If they can see the player, they move towards them. The knight class is basic
    if(this->x >= -1 && this->x <= 1 && this->y >= -1 && this->y <= 1){
        //state = 1;
        float ydist = y-this->y;
        float xdist = x-this->x;
        float totalDistance = sqrt((xdist*xdist) + (ydist*ydist));
        if(this->x >= x-0.1 && this->x + this->y == y){
            std::cout << "Target: Hit. Commencing fire.";
        }
        move((totalDistance * sin((ydist/totalDistance)))/500, (totalDistance * cos((xdist/totalDistance)))/500);
    }
}
void Knight::move(float deltax, float deltay){
    x += deltax;
    y += deltay;
    idleSprite->move(deltax, deltay);
    attackSprite->move(deltax, deltay);
    runSprite->move(deltax, deltay);
    hitbox->move(deltax, deltay);
}