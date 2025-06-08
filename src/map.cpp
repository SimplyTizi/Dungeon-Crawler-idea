#include "map.hpp"
#include <iostream>
#include <fstream>
#include <string>

#define FLOOR { 200, 200, 200, 255 }
#define WALL { 255, 0, 0, 255 }

using namespace std;
void Map::load_RW(SDL_Renderer * renderer, SDL_Window * window) {
	Renderer_m = renderer;
	Window_m = window;

}

void Map::AssingTexture(Tile *temp_t) {
	switch (temp_t->type) {
	case '.':
		temp_t->color = FLOOR;
		break;
	case 'X':
		temp_t->color = WALL;
		break;
	case 'O':
		temp_t->color = FLOOR;
		Player.Hitbox.x = temp_t->pos.x;
		Player.Hitbox.y = temp_t->pos.y;
		Player.Hitbox.h = temp_t->size;
		Player.Hitbox.w = temp_t->size;
		break;
	default:
		std::cout << "couldn't load: " << temp_t->type << std::endl;
		temp_t->color = { 0, 0, 0, 255 };
		break;
	}

	temp_t->rectangle.x = temp_t->pos.x * temp_t->size;
	temp_t->rectangle.y = temp_t->pos.y * temp_t->size;
	temp_t->rectangle.w = temp_t->size;
	temp_t->rectangle.h = temp_t->size;
}


void Map::LoadMap() {
	if (map_location == "Null") {
		std::cout << "Error: map wasnt load, the map location variable is equal to 'null' " << std::endl;
		return;
	}

	std::fstream filein(map_location);

	if (!filein.is_open()) {
		std::cout << "Error: Unable to open file!" << std::endl;
		return;
	}
	string line;
	Tile temp_t(Screen_height);
	int i = 0;
	int j = 0;
	while (getline(filein, line)) {
		std::cout << line << std::endl;
		while (line[i] != 'E') {
			temp_t.type = line[i];
			temp_t.pos.x = i;
			temp_t.pos.y = j;
			temp_t.Assing_Texture();
			l_tiles.push_back(temp_t);
			
			i++;
		}
		j++;
		i = 0;
	}	
	std::cout << "map loaded succesfully!" << std::endl;

}

