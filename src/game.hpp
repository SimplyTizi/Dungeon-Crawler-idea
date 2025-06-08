#ifndef game_hpp
#define game_hpp
#include <SDL2/SDL.h>
#include <stdio.h>
#include "map.hpp"
#include "camera.hpp"


class Game {
public:
	int Screen_Height;
	int Screen_Width;
	Map map;
	Camera camera;
	Game();
	~Game();
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void initialize();
	void handle_events();
	void DrawMap();
	void DrawPlayer();
	void update();
	void render();
	void clean();
	bool running() { return is_running; }
private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;
};


#endif // game_hpp 
