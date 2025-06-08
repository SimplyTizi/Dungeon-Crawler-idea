#pragma once

#include "game.hpp"

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* filename,SDL_Renderer* ren);
private:

};