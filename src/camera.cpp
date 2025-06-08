#include "camera.hpp"
#include "map.hpp"
#include <algorithm>
char x_i;
char y_i;

void Camera::move(Map& map) {
	offset = { 0,0 };

	if (!horizontal_input.empty()) {
		x_i = horizontal_input.front();
		switch (x_i) {
			case 'l':
				offset.x = 10;
				break;
			case 'r':
				offset.x = -10;
				break;
			default:
				break;
		}
	}

	if (!vertical_input.empty()) {
		y_i = vertical_input.front();
		switch (y_i) {
			case 'u':
				offset.y = 10;
				break;
			case 'd':
				offset.y = -10;
				break;
			default:
				break;
		}
	}

	for (size_t i = 0; i < map.l_tiles.size(); i++) {
		map.l_tiles[i].rectangle.x += offset.x;
		map.l_tiles[i].rectangle.y += offset.y;
	}
};

void Camera::keydown(SDL_Keycode key) {
	switch (key) {
		case SDLK_RIGHT:
			horizontal_input.push_front('r');
			break;
		case SDLK_LEFT:
			horizontal_input.push_front('l');
			break;
		case SDLK_UP:
			vertical_input.push_front('u');
			break;
		case SDLK_DOWN:
			vertical_input.push_front('d');
			break;
	}
}

void Camera::keyup(SDL_Keycode key) {
	switch (key) {
		case SDLK_RIGHT:
		case SDLK_LEFT: {
			char key_to_erase = (key == SDLK_RIGHT) ? 'r' : 'l';
			horizontal_input.erase(
				std::remove(horizontal_input.begin(), horizontal_input.end(), key_to_erase),
				horizontal_input.end()
			);
			break;
		}

		case SDLK_UP:
		case SDLK_DOWN: {
			char key_to_erase = (key == SDLK_UP) ? 'u' : 'd';
			vertical_input.erase(
				std::remove(vertical_input.begin(), vertical_input.end(), key_to_erase),
				vertical_input.end()
			);
			break;
		}
	}
}