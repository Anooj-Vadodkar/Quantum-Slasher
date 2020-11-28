#pragma once

class Shape{
public:
	virtual void draw(float zindex = 0.1) const = 0;
	
	virtual ~Shape() {}
};
