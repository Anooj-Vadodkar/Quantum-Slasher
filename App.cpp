#include <iostream>
#include "App.h"
#include <stdlib.h> 
static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    srand(time(NULL));
    player = new Player(0.2, 0.2, 0.6, 0.6);
    std::cout << currentLevel << std::endl;
} 

void App::draw() {
    if(currentLevel == 0){

    } else if(currentLevel == 4){

    } else {
        level->draw();
        for(int i = 0; (int) i < enemies.size(); i++){
            enemies[i]->draw();
            enemies[i]->moveToPlayer(0.2, 0);
            if(enemies[i]->getX() >= 0 && enemies[i]->getX() < 0.2 && enemies[i]->getY() >= -0.1 && enemies[i]->getY() < 0.1){
                enemies.erase(enemies.begin() + i);
                player->damage();
            }
        }
        //std::cout << level->getX() << " " << level->getY() << std::endl;
        if(level->getPortalX() >= 0 && level->getPortalX() < 0.3 && level->getPortalY() < 0.2 && level->getPortalY() > -0.15){
            player->addHealth();
            incrementLevel();
        } 
        player->draw();
    }
    singleton->redraw();
}
// Increments and spawns each of the levels. Enemies are added and created here, but the portal location and general level logic is
// handled in Level.h
void App::incrementLevel(){
    currentLevel++;
    if(currentLevel == 0){
        level = new Level(1);
        float merchantX;
        float merchantY;
        for(int i = 0; i < 10; i++){
            merchantX = (rand()%40+1)/10;
            merchantY = (rand()%40+1)/10;
            Sprite* idleSprite = new Sprite("Assets/EnemyAssets/merchantidle.png", 1, 4, merchantX+(-0.3), merchantY+0.2, 0.5, 0.5);
            Sprite* runSprite = new Sprite("Assets/EnemyAssets/merchantwalk.png", 1, 5, merchantX+(-0.3), merchantY-(-0.3), 0.5, 0.5);
            enemies.push_back(new Merchant(idleSprite, runSprite, merchantX, merchantY, 0.2, 0.2, 0.8f, 0.8f));
        } 
    }
    else if(currentLevel == 1){
        enemies.clear();
        level = new Level(2);
        float droneX;
        float droneY;
        for(int i = 0; i < 10; i++){
            droneX = (rand()%40+1)/10;
            droneY = (rand()%40+1)/10;
            Sprite* idleSprite = new Sprite("Assets/EnemyAssets/droneidle.png", 1, 1, droneX-0.45, droneY+0.5, 0.6, 0.4);
            Sprite* runSprite = new Sprite("Assets/EnemyAssets/dronewalk.png",  6, 1, droneX-0.45, droneY+0.5, 0.8, 0.4);
            enemies.push_back(new Drone(idleSprite, runSprite, droneX, droneY, 0.2, 0.2, 0.8f, 0.8f));
        }
    } else if(currentLevel == 2){
        enemies.clear();
        level = new Level(2);
        float stormheadX;
        float stormheadY;
        for(int i = 0; i < 10; i++){
            stormheadX = (rand()%40+1)/10;
            stormheadX = (rand()%40+1)/10;
            Sprite* idleSprite = new Sprite("Assets/EnemyAssets/stormheadidle.png", 9, 1, stormheadX-0.45, stormheadY+0.7, 0.6, 0.4);
            Sprite* runSprite = new Sprite("Assets/EnemyAssets/stormheadrun.png",  10, 1, stormheadX-0.45, stormheadY+0.7, 0.8, 0.8);
            enemies.push_back(new Drone(idleSprite, runSprite, stormheadX, stormheadY, 0.2, 0.2, 1, 1));
        }
        
    }
}
void App::leftMouseDown(float x, float y){
    std::cout << "X: " << x << " Y: " << y << std::endl;

}
void App::keyDown(unsigned char key, float x, float y){
    if(currentLevel > 0 && currentLevel < 4){
        if(key == 'w'){
            for(auto i = enemies.begin(); i != enemies.end(); i++){
                (*i)->move(0, -0.05);
            }
            level->move(0, -0.05);
            if(player->getState() != 2){
                player->setState(2);
            }
        }
        if(key == 'a'){
            if(level->getX() <= -1.5){
                for(auto i = enemies.begin(); i != enemies.end(); i++){
                    (*i)->move(0.05, 0);
                }
                level->move(0.05, 0);
            }
            if(player->playerRight()){
                player->flip();
            }
            if(player->getState() != 2){
                player->setState(2);
            }
        }
        if(key == 's'){
            for(auto i = enemies.begin(); i != enemies.end(); i++){
                (*i)->move(0, 0.05);
            }
            level->move(0, 0.05);
            if(player->getState() != 2){
                player->setState(2);
            }
        }
        if(key == 'd'){
            for(auto i = enemies.begin(); i != enemies.end(); i++){
                (*i)->move(-0.05, 0);
            }
            level->move(-0.05, 0);
            if(player->getState() != 2){
                player->setState(2);
            }
            if(!player->playerRight()){
                player->flip();
            }
        }
        if(key == ' '){
            for(int i = 0; (int) i < enemies.size(); i++){
                // Check whether there are any enemies inside of the attack. The first one is for enemies that are
                // to the right of the player (done when the player is facing the right), and the second one is done
                // for enemies that are on the left of the player (player is facing left)
                if(player->playerRight()){
                    if(enemies[i]->getX() >= 0.25 && enemies[i]->getX() < 0.6 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
                        enemies[i]->move(10000, 10000);
                        enemies.erase(enemies.begin() + i);
                    }
                } else {
                    if(enemies[i]->getX() >= -0.25 && enemies[i]->getX() < 0 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
                        enemies[i]->move(10000, 10000);
                        enemies.erase(enemies.begin() + i);
                    }
                }
            }
            player->setState(1);
        }
    }
    if (key == 27){
        exit(0);
    }
}

void App::keyUp(unsigned char key, float x, float y){
    if(key == 'w' || key == 'a' || key == 's' || key == 'd'){
        player->setState(0);
    }
}

App::~App(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
