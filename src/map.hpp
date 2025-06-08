#ifndef map_hpp
#define map_hpp
#include "Tile.hpp"
#include "Character.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <vector>
#include <string>

class Map {
public:
	int Screen_height;
	int Screen_width;
	SDL_Renderer* Renderer_m;
	SDL_Window* Window_m;
	std::string map_location;
	unsigned int tile_quantity;
	std::vector<Tile> l_tiles;
	Character Player;
	float zoom_factor;

	void load_RW(SDL_Renderer* renderer, SDL_Window* window);
	void LoadMap();
	void AssingTexture(Tile* temp_t);
	void Draw();

private:
	
};


#endif // game_hpp 
