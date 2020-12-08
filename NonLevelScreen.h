#ifndef NONLEVELSCREEN_H
#define NONLEVELSCREEN_H

#include "Text.h"
#include "Rect.h"
#include <vector>
class NonLevelScreen{
    Rect* button;
    bool active;
    std::vector<Text*> onScreenText;
    int currentScreen = 0;
    public:
        NonLevelScreen(int);
        bool contains(float, float); 
        void draw();
        bool isActive();
};

#endif