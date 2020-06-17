#pragma once

#include "Window.h"
class rect : public Window
{
public:
	rect(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a); //a stands for alpha; r,g,b are for RGB
	~rect();

	void draw() const;
	void pollEvents(SDL_Event event);


private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
};

