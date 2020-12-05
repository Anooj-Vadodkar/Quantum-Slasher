#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Level.h"
#include "Enemy.h"
#include "Knight.h"
#include "Drone.h"
#include "Player.h"
class App: public GlutApp {

std::vector<Shape*> shapes;
Player* player;
Level* level;
std::vector<Enemy*> enemies;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
    void keyUp(unsigned char key, float x, float y);
    void leftMouseDown(float, float);
    ~App();
};

#endif
