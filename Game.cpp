#include<iostream>
#include "Game.h"

Game::Game(){
    srand(time(NULL));
    player = new Player(0.2, 0.2, 0.6, 0.6);
    nonlevelscreens = new NonLevelScreen(0);
    std::cout << currentLevel << std::endl;
} 

void Game::draw() {
    // What is drawn depends on the level. If the case is 0, the player is on the title screen. If the case is 4, the player is
    // on the game over screen. If the case if 5, then the player is on the victory screen. Otherwise, the level is drawn.
    switch(currentLevel){
        case 0:
            nonlevelscreens->draw();
            break;
        case 4:
            nonlevelscreens->draw();
            break;
        case 5:
            nonlevelscreens->draw();
            break;
        default:
            level->draw();
            for(int i = 0; (int) i < enemies.size(); i++){
                enemies[i]->draw();
                enemies[i]->moveToPlayer(0.2, 0);
                if(enemies[i]->getX() >= 0.2 && enemies[i]->getX() < 0.4 && enemies[i]->getY() >= -0.1 && enemies[i]->getY() < 0.1){
                    enemies.erase(enemies.begin() + i);
                    if(player->damage()){
                        enemies.clear();
                        nonlevelscreens = new NonLevelScreen(1);
                        currentLevel = 4;
                    }
                }
            }
            //std::cout << level->getX() << " " << level->getY() << std::endl;
            if(level->getPortalX() >= 0 && level->getPortalX() < 0.3 && level->getPortalY() < 0.2 && level->getPortalY() > -0.15){
                if(currentLevel == 3){
                    enemies.clear();
                    nonlevelscreens = new NonLevelScreen(2);
                    currentLevel = 5;
                }else  {
                    player->addHealth();
                    incrementLevel();
                }
            } 
            player->draw();
            break;
    }
}
// Increments and spawns each of the levels. Enemies are added and created here, but the portal location and general level logic is
// handled in Level.h. The enemy created depends on the level, and this is merely the creation of the level. 
void Game::incrementLevel(){
    if(currentLevel == 0){
        player->addHealth();
        player->addHealth();
        player->addHealth();
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
        std::cout << "portalX " << level->getPortalX() << " portalY " << level->getPortalY(); 
    }
    else if(currentLevel == 1){
        enemies.clear();
        level = new Level(2);
        float droneX;
        float droneY;
        for(int i = 0; i < 10; i++){
            droneX = (rand()%40+1)/10;
            droneY = (rand()%40+1)/10;
            Sprite* idleSprite = new Sprite("Assets/EnemyAssets/droneidle.png", 1, 1, droneX-0.4, droneY+0.35, 0.6, 0.4);
            Sprite* runSprite = new Sprite("Assets/EnemyAssets/dronewalk.png",  6, 1, droneX-0.4, droneY+0.35, 0.8, 0.4);
            enemies.push_back(new Drone(idleSprite, runSprite, droneX, droneY, 0.2, 0.2, 0.8f, 0.8f));
        }
    } else if(currentLevel == 2){
        enemies.clear();
        level = new Level(2);
        float stormheadX;
        float stormheadY;
        for(int i = 0; i < 10; i++){
            stormheadX = (rand()%40+1)/10;
            stormheadY = (rand()%40+1)/10;
            Sprite* idleSprite = new Sprite("Assets/EnemyAssets/stormheadidle.png", 9, 1, stormheadX-0.45, stormheadY+0.7, 0.6, 0.4);
            Sprite* runSprite = new Sprite("Assets/EnemyAssets/stormheadrun.png",  10, 1, stormheadX-0.45, stormheadY+0.7, 0.8, 0.8);
            enemies.push_back(new Drone(idleSprite, runSprite, stormheadX, stormheadY, 0.2, 0.2, 1, 1));
        }
        
    }
    currentLevel++;
}
void Game::leftMouseDown(float x, float y){
    if(nonlevelscreens->isActive()){
        if(nonlevelscreens->contains(x, y)){
            currentLevel = 0;
            incrementLevel(); 
        }
    }

}
void Game::keyDown(unsigned char key, float x, float y){
    if(currentLevel > 0 && currentLevel < 4){
        if(key == 'w'){
            if(level->getY() >= 1.15){
                for(auto i = enemies.begin(); i != enemies.end(); i++){
                    (*i)->move(0, -0.05);
                }
                level->move(0, -0.05);
            }
            if(player->getState() != 2){
                player->setState(2);
            }
        }
        if(key == 'a'){
            if(level->getX() <= -1.4){
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
            if(level->getY() <= 7.4){
                for(auto i = enemies.begin(); i != enemies.end(); i++){
                    (*i)->move(0, 0.05);
                }
                level->move(0, 0.05);
            }
            if(player->getState() != 2){
                player->setState(2);
            }
        }
        if(key == 'd'){
            if(level->getX() >= -7.45){
                for(auto i = enemies.begin(); i != enemies.end(); i++){
                    (*i)->move(-0.05, 0);
                }
                level->move(-0.05, 0);
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
                // Check whether there are any enemies inside of the attack. The first one is for enemies that are
                // to the right of the player (done when the player is facing the right), and the second one is done
                // for enemies that are on the left of the player (player is facing left)
                if(player->playerRight()){
                    if(enemies[i]->getX() >= 0.25 && enemies[i]->getX() < 0.75 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
                        enemies[i]->move(10000, 10000);
                        enemies.erase(enemies.begin() + i);
                    }
                } else {
                    if(enemies[i]->getX() >= -0.25 && enemies[i]->getX() < 0.25 && enemies[i]->getY() >= -0.2 && enemies[i]->getY() < 0.2){
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

void Game::keyUp(unsigned char key, float x, float y){
    if(key == 'w' || key == 'a' || key == 's' || key == 'd'){
        player->setState(0);
    }
}