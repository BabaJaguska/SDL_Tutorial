#include "Window.h"
#include "rect.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;
constexpr auto RECT_HEIGHT = 120;
constexpr auto RECT_WIDTH = 120;
constexpr auto RECT_X_POS = 100;
constexpr auto RECT_Y_POS = 100;
constexpr auto RECT_R = 200;
constexpr auto RECT_G = 0;
constexpr auto RECT_B = 200;
constexpr auto RECT_ALPHA = 255;

void pollEvents(Window &window, rect &rect) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		rect.pollEvents(event);
		window.pollEvents(event);
	}
}


int main(int argc, char **argv) {



	Window window("SDL_Hello_Dude", WINDOW_WIDTH, WINDOW_HEIGHT);
	rect rect(window,RECT_WIDTH,
		RECT_HEIGHT,
		RECT_X_POS,
		RECT_Y_POS,
		RECT_R,
		RECT_G,
		RECT_B,
		RECT_ALPHA);

	while (!window.isClosed()) {
		pollEvents(window, rect);
		rect.draw();	
		window.clear();

	}



	return 0;
}