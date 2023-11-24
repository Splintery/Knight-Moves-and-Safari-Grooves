#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../controller/Controller.hpp"
// #include <array>

using namespace sf;

class ButinState: public State {
	public:
		ButinState(ControllerDataRef data);
		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
	private:
		ControllerDataRef data;

		// array<array<Sprite>> spriteBoard;

		Vector2i fromTile;
		Vector2i toTile;
		bool moveReady;
};

#endif