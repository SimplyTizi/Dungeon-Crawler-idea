
#include "game.hpp"
#include <iostream>
#include "textureManager.h"
#include "map.hpp"
#include "Tile.hpp"
#include "camera.hpp"
#include <deque>


Game::Game() {
}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	Screen_Height = height;
	Screen_Width = width;
	
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialised!..." << std::endl;

		window = SDL_CreateWindow("not a zelda", xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window Created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created!" << std::endl;
		}

		is_running = true;
	}
	else
	{
		is_running = false;
	}
}

void Game::initialize() {
	map.load_RW(renderer, window);
	map.map_location = "maps/tilemap.txt";
	map.Screen_height = Screen_Height;
	map.LoadMap();


}

void Game::handle_events() {
	SDL_Event Event;

	while (SDL_PollEvent(&Event)) {
		switch (Event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			if(Event.key.repeat == 0){camera.keydown(Event.key.keysym.sym);}
			break;
		case SDL_KEYUP:
			camera.keyup(Event.key.keysym.sym);
			break;
		default:
			break;
		}
	}
}

void Game::update() {
	camera.move(map);

}

void Game::DrawMap() {
	for (size_t i = 0; i < map.l_tiles.size(); i++) {
		SDL_SetRenderDrawColor(renderer, map.l_tiles[i].color.r, map.l_tiles[i].color.g, map.l_tiles[i].color.b, map.l_tiles[i].color.a);
		SDL_RenderFillRect(renderer, &map.l_tiles[i].rectangle);
	}
}

void Game::render() {
	// Limpia el frame anterior una sola vez
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color de fondo (negro, por ejemplo)
	SDL_RenderClear(renderer);


	DrawMap();
	//DrawPlayer();
	// Dibuja todos los tiles
	

	// Muestra el frame ya dibujado
	SDL_RenderPresent(renderer);
}


void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "game cleaned" << std::endl;
}
