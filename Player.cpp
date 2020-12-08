#include "Player.h"
#include<iostream>

Player::Player(float w, float h, int spritew, int spriteh){
    idleSprite = new Sprite("Assets/HeroAssets/playeridle.png", 1, 4, -0.1, 0.3, 0.5, 0.3);
    attackSprite = new Sprite("Assets/HeroAssets/playerattack.png", 1, 6, -0.1, 0.3, 0.5, 0.3);
    runSprite = new Sprite("Assets/HeroAssets/playerrun.png", 1, 6, -0.1, 0.3, 0.5, 0.3);
    healthIndicator.push_back(new Sprite("Assets/LevelAssets/hearts.png", 1, 1, -1.3, 0.95, 0.25, 0.1875));
    healthIndicator.push_back(new Sprite("Assets/LevelAssets/hearts.png", 1, 1, -1.05, 0.95, 0.25, 0.1875));
    healthIndicator.push_back(new Sprite("Assets/LevelAssets/hearts.png", 1, 1, -0.8, 0.95, 0.25, 0.1875));
    this->w = w;
    this->h = h;
    this->spritew = spritew;
    this->spriteh = spriteh;
    x = 0;
    y = 0;
    health = MAX_HEALTH;
}

void Player::draw(){
    frame++;
    for(auto i = healthIndicator.begin(); i != healthIndicator.end(); i++){
        (*i)->draw();
    }
    switch(state){
        case 0:
            if(frame == 20){
                idleSprite->reset();
                frame = 0;
            }
            if(frame%5 == 0){
                idleSprite->advance();
            }
            idleSprite->draw(0.5);
            break;
        case 1:
            if(frame == 18){
                    attackSprite->reset();
                    state = 0;
                    frame = 0;
                }
                if(frame%3 == 0){
                    attackSprite->advance();
                }
                attackSprite->draw(0.5);
            break;
        case 2:
            if(frame == 18){
                runSprite->reset();
                frame = 0;
            }
            if(frame%3 == 0){
                runSprite->advance();
            }
            runSprite->draw(0.5);
            break;
    }   
    
    //hitbox->draw(0.5);
}

bool Player::playerRight(){
    return isRight;
}
void Player::attack(){
    std::cout << "I cast fist" << std::endl;
    frame = 0;
    state = 1;
}
void Player::setState(int x){
    frame = 0;
    state = x;
}
void Player::flip(){
    isRight = !isRight;
    attackSprite->flip();
    runSprite->flip();
    idleSprite->flip();
}
int Player::getState(){
    return state;
}
bool Player::damage(){
    health--;
    healthIndicator.pop_back();
    return health == 0;
}
void Player::addHealth(){
    if(health < MAX_HEALTH){
        std::cout << health << std::endl;
        health++;
        healthIndicator.push_back(new Sprite("Assets/LevelAssets/hearts.png", 1, 1, -1.3 + (0.25 * (health-1)), 0.95, 0.25, 0.1875));
    }
}

int Player::getHealth(){
    return health;
}