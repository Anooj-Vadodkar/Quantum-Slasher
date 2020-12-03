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
        float spritew;
        float spriteh;
        float speed;
        float x;
        float y;
    public:
        Enemy(Sprite* idleSprite, Sprite* runSprite, Sprite* attackSprite, Hitbox* newHitbox, float x, float y, float w, float h, int spritew, int spriteh){
            this->idleSprite = idleSprite;
            this->runSprite = runSprite;
            this->attackSprite = attackSprite;
            hitbox = newHitbox;
            this->w = w;
            this->h = h;
            this->x = x+(w/2);
            this->y = y-(h/2);
            this->spritew = spritew;
            this->spriteh = spriteh;
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
                    //if(speed )
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
            //hitbox->draw(0);
        }
        float getX(){return x;};
        float getY(){return y;};
        Hitbox* getHitbox(){return hitbox;};
        void moveToPlayer();
        void move(float deltax, float deltay){
            x += deltax;
            y += deltay;
        }
        ~Enemy(){
            delete this;
        }
};
#endif