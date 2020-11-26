#include <iostream>
#include "App.h"

static App* singleton;

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    shapes.push_back(new TexRect("lion.png", -1, 1, 2, 2));
    shapes.push_back(new Rect());
    shapes.push_back(new Hitbox(-0.5, -0.5, 0.2, 0.2));
    shapes.push_back(new Circle());
} 

void App::draw() const {
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        (*i)->draw();
    }
    Hitbox* box = (Hitbox*) shapes[2];
    box->move(0.001, 0.001);
    singleton->redraw();
}

void App::leftMouseDown(float x, float y){
    Hitbox* box = (Hitbox*) shapes[2];
    std::cout << "X: " << x << " Y: " << y << std::endl;
    std::cout << "Hitbox Area: " << box->getX() << " " << (box->getX() + box->getW()) << " " << box->getY()  << " " << (box->getY() - box->getH()) << std::endl;
    if(box->contains(x, y)){
        std::cout << "Ouch" << std::endl;
    }
}
void App::keyDown(unsigned char key, float x, float y){
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
