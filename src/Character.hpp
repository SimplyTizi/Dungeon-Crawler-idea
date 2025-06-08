#ifndef player_hpp
#define player_hpp
#include <SDL2/SDL.h>
#include "tile.hpp"
class Character {
public:
	int size;
	SDL_Rect Hitbox;


	Character();
	~Character();

	void Draw();

	void move();
};

#endif