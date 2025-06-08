#include "game.hpp"
#include <SDL_image.h>
#include <iostream>
Game* game = nullptr;

int main(int argc, char* argv[]) {
	const int fps = 60;
	const int framedelay = 1000 / fps;

	int screen_height = 600;
	int screen_width = 400;

	Uint32 framestart;
	int frametime;
	game = new Game();

	game->init(" maguitos engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_height, screen_width, false);
	game->initialize();
	while (game->running()) {
		framestart = SDL_GetTicks();

		game->handle_events();
		game->update();
		game->render();
		frametime = SDL_GetTicks() - framestart;
		if (framedelay > frametime) {
			SDL_Delay(framedelay - frametime);
		}
	}

	game->clean();
	
	return 0;
}