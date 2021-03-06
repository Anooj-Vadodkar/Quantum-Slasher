#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"
#include<iostream>
class Enemy{
    protected:
        int state = 0;
        Sprite* idleSprite;
        Sprite* runSprite;
        bool isRight;
        int frame = 0;
        float w;
        float h;
        float spritew;
        float spriteh;
        float speed;
        float x;
        float y;
    public:
        Enemy(Sprite* idleSprite, Sprite* runSprite, float x, float y, float w, float h, int spritew, int spriteh, float speed){
            this->idleSprite = idleSprite;
            this->runSprite = runSprite;
            this->w = w;
            this->h = h;
            this->x = x+(w/2);
            this->y = y-(h/2);
            this->spritew = spritew;
            this->spriteh = spriteh;
            this->speed = speed;
            isRight = x > 0;
        }
        void draw(){
            frame++;
            if(x > -0.9 && x < 0.9 && y < 0.9 && y > 0.9){
                if(frame == 8){
                    idleSprite->reset();
                    frame = 0;
                }
                if(frame%2 == 0){
                    idleSprite->advance();
                }
                idleSprite->draw(0.5);
            } else {
                if(x < 0 && !isRight){
                    isRight = true;
                    runSprite->flip();
                } else if(x > 0 && isRight){
                    isRight = false;
                    runSprite->flip();
                }
                if(frame == 10){
                    runSprite->reset();
                    frame = 0;
                }
                if(frame%2 == 0){
                    runSprite->advance();
                }
                runSprite->draw(0.5);
            }
        }
        float getX(){return x;};
        float getY(){return y;};
        virtual void moveToPlayer(float x, float y){};
        void move(float deltax, float deltay){
            x += deltax;
            y += deltay;
            idleSprite->move(deltax, deltay);
            runSprite->move(deltax, deltay);
        }
        ~Enemy(){
            x = 1000;
            y = 1000;
        }
};
#endif