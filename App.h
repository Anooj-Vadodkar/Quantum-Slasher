#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Hitbox.h"
#include "Level.h"
#include "Enemy.h"
#include "Knight.h"
class App: public GlutApp {

std::vector<Shape*> shapes;
Level* level;
std::vector<Enemy*> knights;
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);
    void leftMouseDown(float, float);
    ~App();
};

#endif
