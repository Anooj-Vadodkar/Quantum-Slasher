#ifndef App_h
#define App_h

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
class App: public GlutApp {

std::vector<Shape*> shapes;
int currentLevel = 0;
Player* player;
Level* level;
NonLevelScreen* nonlevelscreens;
std::vector<Enemy*> enemies;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);
    void leftMouseDown(float, float);

    void incrementLevel();
    ~App();
};

#endif
