#include "Tile.hpp"
#include <SDL2/SDL.h>
#include <iostream>

void Tile::draw(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0x00f, 0x00f, 0x00f, 0x00f);
	SDL_RenderDrawRect(renderer, &rectangle);
}

Tile::Tile(int Screenheight) {
	zoom = 1;
	size = (Screenheight / 10) * zoom;
	rectangle.x = pos.x * size;  
	rectangle.y = pos.y * size;
	rectangle.w = size;
	rectangle.h = size;
}

Tile::~Tile() {

}

void Tile::Assing_Texture() {
	switch (type) {
	case 'O':
		color = { 255, 255, 255, 255 };

		break;
	case 'X':
		color = { 255, 0, 0, 255 };
		break;
	case '.':
		color = { 200, 200, 200, 255 };
		break;
	default:
		std::cout << "couldn't load: " << type << std::endl;
		color = { 0, 0, 0, 255 };
		break;
	}

	rectangle.x = pos.x * size;
	rectangle.y = pos.y * size;
	rectangle.w = size;
	rectangle.h = size;
}
