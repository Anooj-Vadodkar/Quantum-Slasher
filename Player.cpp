#include "Player.h"
#include<iostream>

Player::Player(float w, float h, int spritew, int spriteh){
    Sprite* idleSprite = new Sprite("Assets/HeroAssets/playeridle.png", 4, 1, -0.1, 0.3, 1.1, 0.55);
    Sprite* attackSprite = new Sprite("Assets/HeroAssets/playerattack.png", 13, 1, -0.1, 0.3, 1, 0.55);
    Sprite* runSprite = new Sprite("Assets/HeroAssets/playerrun.png", 1, 8, 0, 0, 0.5, 0.5);
    Sprite* healthIndicator = new Sprite("Assets/LevelAssets/hearts.png", 1, 1, -0.7, 0.7, 0.4, 0.3);
    this->idleSprite = idleSprite;
    this->runSprite = runSprite;
    this->attackSprite = attackSprite;
    this->healthIndicator = healthIndicator;
    this->w = w;
    this->h = h;
    this->spritew = spritew;
    this->spriteh = spriteh;
    x = 0;
    y = 0;
    hitbox = new Hitbox(0.05, 0, 0.2, 0.3);
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
            if(frame == 39){
                attackSprite->reset();
                state = 0;
                frame = 0;
            }
            if(frame%3 == 0){
                attackSprite->advance();
            }
            attackSprite->draw(0.5);
            break;
    }
    //hitbox->draw(0.5);
}

void Player::attack(){
    std::cout << "I cast fist" << std::endl;
    frame = 0;
    state = 1;
}