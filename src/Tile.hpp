#ifndef tile_hpp
#define tile_hpp
#include "DataStructure.hpp"
#include <SDL2/SDL.h>

class Tile {
public:
	SDL_Rect rectangle;
	char type = 0;
	int size;
	Vector2 pos;
	float zoom;
	SDL_Color color;
	// We define "nothing" (a black tile) as 0

	Tile(int Screenheight);

	~Tile();

	void draw(SDL_Renderer* renderer);

	void Assing_Texture();

private:

};

#endif