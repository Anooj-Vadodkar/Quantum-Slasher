#include "Text.h"
#include "GlutApp.h"

Text::Text(char* text, int textLength, float x, float y, float r, float g, float b){
    this->text = text;
    this->textLength = textLength;
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    font = GLUT_BITMAP_TIMES_ROMAN_24;
}

void Text::setText(char* text, int textLength){
    this->text = text;
    this->textLength = textLength;
}

void Text::renderText(int width){

    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < textLength; i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / width)*2;
    }
}
