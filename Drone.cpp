#include "Drone.h"
#include <cmath>
#include <iostream>
#define pi 3.1415
void Drone::moveToPlayer(float x, float y){
    if(this->x >= -1 && this->x <= 1 && this->y >= -1 && this->y <= 1){
        //state = 1;
        float ydist = y-this->y;
        float xdist = x-this->x;
        float totalDistance = sqrt((xdist*xdist) + (ydist*ydist));
        float normalizedVectorX = xdist/totalDistance;
        float normalizedVectorY = ydist/totalDistance;
        // Making the moving interesting here; The enemy slows down and speeds up 
        // in line with a sinusoid. 
        float scalar = abs(sin((pi * degree)/180));
        degree++;
        move(normalizedVectorX * speed * scalar, normalizedVectorY * speed * scalar);
    }
}