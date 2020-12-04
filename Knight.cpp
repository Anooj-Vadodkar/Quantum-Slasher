#include <iostream>
#include "Knight.h"
#include <cmath>

void Knight::moveToPlayer(float x, float y){
    // This is the basic function that defines how the knight class enemy interacts with the player;
    // If they can see the player, they move towards them. The knight class is basic
    if(this->x >= -1 && this->x <= 1 && this->y >= -1 && this->y <= 1){
        //state = 1;
        float ydist = y-this->y;
        float xdist = x-this->x;
        float totalDistance = sqrt((xdist*xdist) + (ydist*ydist));
        float normalizedVectorX = xdist/totalDistance;
        float normalizedVectorY = ydist/totalDistance;
        std::cout << this->x << " " << this->y << std::endl;
        move(normalizedVectorX*speed, normalizedVectorY*speed);
    }
}
void Knight::move(float deltax, float deltay){
    x += deltax;
    y += deltay;
    idleSprite->move(deltax, deltay);
    runSprite->move(deltax, deltay);
    hitbox->move(deltax, deltay);
}