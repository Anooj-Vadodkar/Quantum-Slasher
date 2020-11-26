#include "Hitbox.h"
#include "GlutApp.h"

Hitbox::Hitbox(float x, float y, float w, float h){
    // The hitbox is, by nature, something the player shouldn't be able to see. At most. I'll be using it for bug detection, which is why I want to be able to draw it.
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->a = 0.5;
}

void Hitbox::move(float deltaX, float deltaY){
    this->x += deltaX;
    this->y += deltaY;
}
void Hitbox::draw(float z) const{
    glColor4f(0, 0, 0, a);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}
float Hitbox::getX(){
    return this->x;
}

float Hitbox::getY(){
    return this->y;
}

float Hitbox::getW(){
    return this->w;
}

float Hitbox::getH(){
    return this->h;
}

bool Hitbox::contains(Hitbox* otherHitbox){
    if(otherHitbox->getX() >= this->x && otherHitbox->getX() <= this->x + w && otherHitbox->getY() <= this->y && otherHitbox->getY() >= this->y - h){
        return true;
    }
}

bool Hitbox::contains(float x, float y){
    return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - h;
}