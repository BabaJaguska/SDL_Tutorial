#include "rect.h"



rect::rect(const Window &window, int w, int h, int x, int y, int r, int g, int b, int a):
	Window(window), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}


rect::~rect()
{
}

void rect::draw() const
{
	SDL_Rect rect;

	rect.w = _w;
	rect.h = _h;
	rect.x = _x;
	rect.y = _y;

	SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(_renderer, &rect);
}

void rect::pollEvents(SDL_Event event)
{
	
	
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			_x -= 10;
			break;
		case SDLK_RIGHT:
			_x += 10;
			break;
		case SDLK_UP:
			_y -= 10;
			break;
		case SDLK_DOWN:
			_y += 10;
			break;
		}
	}
	
}
