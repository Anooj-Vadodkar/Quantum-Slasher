#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include "Hitbox.h"
class Enemy{
    protected:
        int state = 0;
        Sprite* idleSprite;
        Sprite* runSprite;
        Sprite* attackSprite;
        Hitbox* hitbox;
        int frame = 0;
        float w;
        float h;
        float speed;
        float x;
        float y;
    public:
        Enemy(Sprite* idleSprite, Sprite* runSprite, Sprite* attackSprite, Hitbox* newHitbox, float x, float y, float w, float h){
            this->idleSprite = idleSprite;
            this->runSprite = runSprite;
            this->attackSprite = attackSprite;
            hitbox = newHitbox;
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
            this->speed = speed;
        }
        void draw(){
            frame++;
            switch(state){
                case 0: 
                    if(frame == 22){
                        idleSprite->reset();
                        frame = 0;
                    }
                    if(frame%2 == 0){
                        idleSprite->advance();
                    }
                    idleSprite->draw(0.5);
                    break;
                case 1: 
                    if(frame == 22){
                        idleSprite->reset();
                        frame = 0;
                    }
                    if(frame%2 == 0){
                        runSprite->advance();
                    }
                    runSprite->draw(0.5);
                    break;
                case 2: 
                    if(frame == 22){
                        idleSprite->reset();
                        frame = 0;
                    }
                    if(frame%2 == 0){
                        attackSprite->advance();
                    }
                    attackSprite->draw(0.5);
                    break;
            }
        }
        float getX();
        float getY();
        void moveToPlayer(){
            move(0-x, 0-y);
        }
        void move(float deltax, float deltay){
            x += deltax;
            y += deltay;
        }
};
#endif