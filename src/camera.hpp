#ifndef camera_hpp
#define camera_hpp
#include "map.hpp"
#include <deque>
class Camera {
public:
	bool key = false;
	std::deque<char> horizontal_input;
	std::deque<char> vertical_input ;
	int framtime;
	int framestart;
	int frametime;
	int framedelay;
	int finish;
	Vector2 offset = {0,0};

	void move(Map& map);

	void keydown(SDL_Keycode key );

	void keyup(SDL_Keycode key);
};

#endif // !camera_hpp
