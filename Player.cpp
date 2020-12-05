#include "Player.h"
#include<iostream>

Player::Player(float w, float h, int spritew, int spriteh){
    idleSprite = new Sprite("Assets/HeroAssets/playeridle.png", 1, 4, -0.1, 0.3, 0.5, 0.3);
    attackSprite = new Sprite("Assets/HeroAssets/playerattack.png", 1, 6, -0.1, 0.3, 0.5, 0.3);
    runSprite = new Sprite("Assets/HeroAssets/playerrun.png", 1, 6, -0.1, 0.3, 0.5, 0.3);
    healthIndicator = new Sprite("Assets/LevelAssets/hearts.png", 1, 6, -0.7, 0.7, 0.4, 0.3);
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
                std::cout << frame << std::endl;
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