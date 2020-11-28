#ifndef LEVEL_H
#define LEVEL_H

#include "TexRect.h"

class Level: public TexRect{
    float x = -4;
    float y = 4;
public:
    Level(char* image, float width, float height): TexRect(image, -1, 1, width, height){};
    void move(float deltax, float deltay){
        x += deltax;
        y += deltay;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void draw(){
        glBindTexture(GL_TEXTURE_2D, texture_id );
		glEnable(GL_TEXTURE_2D);
		
		glBegin(GL_QUADS);
		glColor4f(1, 1, 1, 1);
		glTexCoord2f(0, 0);
		glVertex3f(x, y - h, 0);
		
		glTexCoord2f(0, 1);
		glVertex3f(x, y, 0);
		
		glTexCoord2f(1, 1);
		glVertex3f(x+w, y, 0);
		
		glTexCoord2f(1, 0);
		glVertex3f(x+w, y - h, 0);
		
		glEnd();
		
		glDisable(GL_TEXTURE_2D);
    }
}; 

#endif