#include <iostream>
#include "App.h"

static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    Sprite* idleSprite = new Sprite("Assets/EnemyAssets/merchantidle.png", 1, 4, -0.4, 0, 0.5, 0.5);
    Sprite* runSprite = new Sprite("Assets/EnemyAssets/merchantwalk.png", 1, 5, -0.4, 0, 0.5, 0.5);
    knights.push_back(new Knight(idleSprite, runSprite, new Hitbox(-0.2, -0.3, 0.2, 0.2), -0.2, -0.3, 0.2, 0.2, 0.8f, 0.8f));
    player = new Player(0.2, 0.2, 0.6, 0.6);
} 

void App::draw() const {
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        (*i)->draw();
    }
    
    for(auto i = knights.begin(); i != knights.end(); i++){
        (*i)->draw();
    }
    Knight* knight = (Knight*) knights[0];
    knight->moveToPlayer(0, 0);
    player->draw();
    singleton->redraw();
}

void App::leftMouseDown(float x, float y){
    std::cout << "X: " << x << " Y: " << y << std::endl;

}
void App::keyDown(unsigned char key, float x, float y){
    Knight* knight = (Knight*) knights[0];
    if(key == 'w'){
        knight->move(0, -0.05);
    }
    if(key == 'a'){
        knight->move(0.05, 0);
    }
    if(key == 's'){
        knight->move(0, 0.05);
    }
    if(key == 'd'){
        knight->move(-0.05, 0);
    }
    if(key == ' '){
        std::vector<Enemy*> enemiesNear;
        for(int i = 0; (int) i < knights.size(); i++){
            // Check whether there are any knights inside of the attack. 
            if(knights[i]->getX() >= 0.25 && knights[i]->getX() < 0.6 && knights[i]->getY() >= -0.2 && knights[i]->getY() < 0.2){
                knights.erase(knights.begin() + i);
                std::cout << "Uh Oh Stinky" << std::endl;
            }
        }
        player->attack();
    }
    if (key == 27){
        exit(0);
    }
}

App::~App(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
