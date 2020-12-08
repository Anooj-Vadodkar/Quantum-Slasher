#ifndef TEXT_H
#define TEXT_H

struct Text{
    char* text;
    float x;
    float y;
    float r;
    float g;
    float b;
    void* font;
    int textLength;
    Text(char* text, int textLength, float x, float y, float r, float g, float b);
    void renderText(int width = 5);
    void setText(char* newText, int textLength);


};

#endif