#include "NonLevelScreen.h"

NonLevelScreen::NonLevelScreen(int screen){
    currentScreen = screen;
    active = true;
    switch(currentScreen){
        case 0:
            onScreenText.push_back(new Text("Quantum Slasher", 16, -0.25, 0.85, 1, 1, 1));
            onScreenText.push_back(new Text("You don't know where you are.", 30, -0.48, 0.65, 1, 1, 1));
            onScreenText.push_back(new Text("You don't how you got here.", 28, -0.42, 0.45, 1, 1, 1));
            onScreenText.push_back(new Text("But you need to get back.", 26, -0.35, 0.25, 1, 1, 1));
            onScreenText.push_back(new Text("Find the portals, and flee this endless sea.", 45, -0.65, 0.05, 1, 1, 1));
            onScreenText.push_back(new Text("Move with the WASD keys, and use space to attack.", 50, -0.75, -0.15, 1, 1, 1));
            button = new Rect(-0.19, -0.85, 0.5, 0.2, 1, 1, 1);
            onScreenText.push_back(new Text("Play", 4, 0, -0.95, 0, 0 ,0));
            break;
        case 1:
            break;
        case 2:
            break;
    }
}

bool NonLevelScreen::contains(float x, float y){
    active = false;
    return button->contains(x, y);
}
bool NonLevelScreen::isActive(){
    return active;
}
void NonLevelScreen::draw(){
    button->draw();
    for(auto i = onScreenText.begin(); i != onScreenText.end(); i++){
        (*i)->renderText(600);
    }
    
}