#include <iostream>
#include "Stormhead.h"
#include <math.h>

void Stormhead::moveToPlayer(float x, float y){
    if(this->x >= -1 && this->x <= 1.2 && this->y >= -1 && this->y <= 1){
        float ydist = y-this->y;
        float xdist = x-this->x;
        float totalDistance = sqrt((xdist*xdist) + (ydist*ydist));
        float normalizedVectorX = xdist/totalDistance;
        float normalizedVectorY = ydist/totalDistance;
        float scalar = log(num);
        num += 0.1;
        move(normalizedVectorX * speed * scalar, normalizedVectorY * speed * scalar);
    }
}