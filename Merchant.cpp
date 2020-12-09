#include <iostream>
#include "Merchant.h"
#include <cmath>

void Merchant::moveToPlayer(float x, float y){
    // This is the basic function that defines how the knight class enemy interacts with the player;
    // If they can see the player, they move towards them. The knight class is basic
    if(this->x >= -1 && this->x <= 1 && this->y >= -1 && this->y <= 1){
        float ydist = y-this->y;
        float xdist = x-this->x;
        float totalDistance = sqrt((xdist*xdist) + (ydist*ydist));
        float normalizedVectorX = xdist/totalDistance;
        float normalizedVectorY = ydist/totalDistance;
        move(normalizedVectorX*speed, normalizedVectorY*speed);
    }
}
