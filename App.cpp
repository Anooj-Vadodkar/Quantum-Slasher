#include <iostream>
#include "App.h"
#include <stdlib.h> 
static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    maingame = new Game();
} 

void App::draw(){
    maingame->mainGameLoop();
    singleton->redraw();
}

void App::leftMouseDown(float x, float y){
    maingame->leftMouseDown(x, y);
}

void App::keyUp(unsigned char key, float x, float y){
    maingame->keyUp(key, x, y);
}

void App::keyDown(unsigned char key, float x, float y){
    maingame->keyDown(key, x, y);
    if (key == 27){
        exit(0);
    }
}

App::~App(){   
    std::cout << "Exiting..." << std::endl;
}

