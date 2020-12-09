#ifndef GAME_H
#define GAME_H

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Level.h"
#include "NonLevelScreen.h"
#include "Enemy.h"
#include "Merchant.h"
#include "Drone.h"
#include "Player.h"
#include "Stormhead.h"

class Game{
    std::vector<Shape*> shapes;
    int currentLevel = 4;
    Player* player;
    Level* level;
    NonLevelScreen* nonlevelscreens;
    std::vector<Enemy*> enemies;
    public:
    
        Game();
        
        void mainGameLoop();
        
        void keyDown(unsigned char key, float x, float y);
        void keyUp(unsigned char key, float x, float y);
        void leftMouseDown(float, float);

        void incrementLevel();
};

#endif