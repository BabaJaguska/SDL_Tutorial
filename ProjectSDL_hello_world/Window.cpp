#include "Window.h"
#include <iostream>

Window::Window(const std::string &title, int width, int height) :

	_title(title), _width(width), _height(height)
{

	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	case SDL_QUIT:
		_closed = true;
		break;

	case SDL_KEYDOWN: // any key press
		switch (event.key.keysym.sym) {
		case SDLK_a:
			std::cout << "You clicked \'A\'\n";
			break;

		case SDLK_ESCAPE:
			_closed = true;
			break;
		}
		break;

	case SDL_MOUSEMOTION:
		std::cout << "X: "<< event.motion.x << ", Y:" << event.motion.y << "\n"; //print mouse coords
		break;

	case SDL_MOUSEBUTTONDOWN:
		std::cout << "HAAA HAAAA you clickd.";
		break;

	default:
		break;
	}
	
}



bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL\n";
		return 0;
	}

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED, // for x
		SDL_WINDOWPOS_CENTERED, // for y
		_width, _height,
		0 // 0 if no additional flags, such as SDL_WINDOW_RESIZABLE
	);


	if (_window == nullptr) {
		std::cerr << "Failed to create window\n";
		return 0;
	}

	_renderer = SDL_CreateRenderer(
		_window,
		-1,
		SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr) {
		std::cerr << "Failed to create renderer\n";
		return 0;
	}

	return true;
}

void Window::clear() const
{
	SDL_RenderPresent(_renderer); // this puts it on the screen
	SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255);
	SDL_RenderClear(_renderer); // gets the color onto the renderer
	
}