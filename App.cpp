#include <iostream>
#include "App.h"

static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    
    //shapes.push_back(new Level("Assets/LevelAssets/level1bg.png", 10, 10));
    //shapes.push_back(new Rect());
    //shapes.push_back(new Hitbox(-0.5, -0.5, 0.2, 0.2));
    shapes.push_back(new Circle());
    //level = new Level("Assets/LevelAssets/level1bg.png", 8, 8);
    Sprite* idleSprite = new Sprite("Assets/EnemyAssets/knightIdle.png", 1, 11, (-0.2-(0.8/2)), (-0.3+(0.8/2)), 0.8, 0.8);
    Sprite* attackSprite = new Sprite("Assets/EnemyAssets/knightAttack.png", 1, 11, (-0.2 - (0.8/2)), (-0.3 + (0.8/2)), 0.8, 0.8);
    Sprite* runSprite = new Sprite("Assets/EnemyAssets/knightRun.png", 1, 11, (-0.2 - (0.8/2)), (-0.1 + (0.8/2)), 0.8, 0.8);
    knights.push_back(new Knight(idleSprite, runSprite, attackSprite, new Hitbox(-0.2, -0.3, 0.2, 0.2), -0.2, -0.3, 0.2, 0.2, 0.8f, 0.8f));
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
    //Hitbox* box = (Hitbox*) shapes[1];
    //level->draw();
    //box->move(0.001, 0.001);
    singleton->redraw();
}

void App::leftMouseDown(float x, float y){
    std::cout << "X: " << x << " Y: " << y << std::endl;
    /*
    Hitbox* box = (Hitbox*) shapes[1];
    
    std::cout << "Hitbox Area: " << box->getX() << " " << (box->getX() + box->getW()) << " " << box->getY()  << " " << (box->getY() - box->getH()) << std::endl;
    if(box->contains(x, y)){
        std::cout << "Ouch" << std::endl;
    }
    */
}
void App::keyDown(unsigned char key, float x, float y){
    if(key == 'w'){
        knights[0]->move(0, -0.1);
    }
    if(key == 'a'){
        knights[0]->move(0.1, 0);
    }
    if(key == 's'){
        knights[0]->move(0, 0.1);
    }
    if(key == 'd'){
        knights[0]->move(-0.1, 0);
    }
    std::cout << knights[0]->getX() << " " << knights[0]->getY() << std::endl;
    
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
