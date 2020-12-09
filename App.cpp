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

// Welcome to my final project for CSE 165! Just a bit of a heads up, there's a good amount of loading times between levels.
// If you're waiting for a while, it's just loading. I hope.

// For the project, I made a game called Quantum Slasher, which is a top down hack and slash game where you try and get
// to a randomly placed portal in the world while avoiding getting hit by enemies. Each enemy moves in a unique way,
// detailed more clearly in 

