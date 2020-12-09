#include "NonLevelScreen.h"

NonLevelScreen::NonLevelScreen(int screen){
    currentScreen = screen;
    active = true;
    switch(currentScreen){
        case 0:
            onScreenText.push_back(new Text("Quantum Slasher", 16, -0.25, 0.85, 1, 1, 1));
            onScreenText.push_back(new Text("You don't know where you are.", 30, -0.48, 0.65, 1, 1, 1));
            onScreenText.push_back(new Text("You don't know how you got here.", 33, -0.51, 0.45, 1, 1, 1));
            onScreenText.push_back(new Text("But you need to get back.", 26, -0.35, 0.25, 1, 1, 1));
            onScreenText.push_back(new Text("Find the portals, and flee this endless sea.", 45, -0.65, 0.05, 1, 1, 1));
            onScreenText.push_back(new Text("Move with the WASD keys, and use space to attack.", 50, -0.75, -0.15, 1, 1, 1));
            onScreenText.push_back(new Text("Loading will take a few seconds, so don't worry!", 49, -0.7, -0.35, 1, 1, 1));
            button = new Rect(-0.19, -0.85, 0.5, 0.2, 1, 1, 1);
            onScreenText.push_back(new Text("Play", 4, 0, -0.95, 0, 0 ,0));
            break;
        case 1:
            button = new Rect(-0.19, -0.85, 0.5, 0.2, 1, 1, 1);
            onScreenText.push_back(new Text("Game Over...", 13, -0.25, 0.85, 1, 1, 1));
            onScreenText.push_back(new Text("Try again?", 11, -0.2, 0.65, 1, 1, 1));
            onScreenText.push_back(new Text("Play", 4, 0, -0.95, 0, 0 ,0));
            break;
        case 2:
        button = new Rect(-0.19, -0.85, 0.5, 0.2, 1, 1, 1);
            onScreenText.push_back(new Text("You win.", 9, -0.15, 0.85, 1, 1, 1));
            onScreenText.push_back(new Text("But your journey is not over.", 30, -0.4, 0.65, 1, 1, 1));
            onScreenText.push_back(new Text("Just as you look away, things returned to how they were.", 57, -0.9, 0.45, 1, 1 ,1));
            onScreenText.push_back(new Text("There is no escape.", 20, -0.3, 0.25, 1, 1 ,1));
            onScreenText.push_back(new Text("Try again?", 11, -0.1, -0.95, 0, 0, 0));
            break;
    }
}
int NonLevelScreen::getScreen(){
    return currentScreen;
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