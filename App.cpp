#include <iostream>
#include "App.h"

static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    Sprite* idleSprite = new Sprite("Assets/EnemyAssets/merchantidle.png", 1, 4, -0.4, 0, 0.5, 0.5);
    Sprite* runSprite = new Sprite("Assets/EnemyAssets/merchantwalk.png", 1, 5, -0.4, 0, 0.5, 0.5);
    enemies.push_back(new Knight(idleSprite, runSprite, -0.2, -0.3, 0.2, 0.2, 0.8f, 0.8f));
    idleSprite = new Sprite("Assets/EnemyAssets/droneidle.png", 1, 1, -0.5, 0.6, 0.6, 0.4);
    runSprite = new Sprite("Assets/EnemyAssets/dronewalk.png", 6, 1, -0.5, 0.6, 0.6, 0.4);
    enemies.push_back(new Drone(idleSprite, runSprite, -0.2, 0.3,  0.2, 0.2, 0.6, 0.4));
    player = new Player(0.2, 0.2, 0.6, 0.6);
} 

void App::draw() {
    for(int i = 0; (int) i < enemies.size(); i++){
        enemies[i]->draw();
        enemies[i]->moveToPlayer(0, 0);
        if(enemies[i]->getX() >= 0 && enemies[i]->getX() < 0.2 && enemies[i]->getY() >= -0.1 && enemies[i]->getY() < 0.1){
            enemies.erase(enemies.begin() + i);
        }
    }
    player->draw();
    singleton->redraw();
}

void App::leftMouseDown(float x, float y){
    std::cout << "X: " << x << " Y: " << y << std::endl;

}
void App::keyDown(unsigned char key, float x, float y){
    if(key == 'w'){
        for(auto i = enemies.begin(); i != enemies.end(); i++){
            (*i)->move(0, -0.05);
        }
        if(player->getState() != 2){
            player->setState(2);
        }
    }
    if(key == 'a'){
        for(auto i = enemies.begin(); i != enemies.end(); i++){
            (*i)->move(0.05, 0);
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
        if(player->getState() != 2){
            player->setState(2);
        }
    }
    if(key == 'd'){
        for(auto i = enemies.begin(); i != enemies.end(); i++){
            (*i)->move(-0.05, 0);
        }
        if(player->getState() != 2){
            player->setState(2);
        }
        if(!player->playerRight()){
            player->flip();
        }
    }
    if(key == ' '){
        for(int i = 0; (int) i < enemies.size(); i++){
            // Check whether there are any enemies inside of the attack. 
            if(player->playerRight()){
                if(enemies[i]->getX() >= 0.25 && enemies[i]->getX() < 0.6 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
                    enemies.erase(enemies.begin() + i);
                }
            } else {
                if(enemies[i]->getX() >= -0.25 && enemies[i]->getX() < 0 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
                    enemies.erase(enemies.begin() + i);
                }
            }
        }
        player->setState(1);
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
