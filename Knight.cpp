#include "Knight.h"


float Knight::getX(){
    return x;
}

float Knight::getY(){
    return y;
}
void Knight::moveToPlayer(){
    // This is the basic function that defines how the knight class enemy interacts with the player;
    // If they can see the player, they move towards them. The knight class is basic
    if(this->x >= -1 && x <= 1 && y >= -1 && y <= 1){
        state = 1;
        move((0-x)/100, (0-y)/100);
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