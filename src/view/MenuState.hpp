#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../controller/Controller.hpp"

using namespace sf;

class MenuState: public State {
	public:
		MenuState(ControllerDataRef data);
		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
	private:
		ControllerDataRef data;
		Clock clock;

		Sprite butinButton;
		Sprite gounkiButton;
		Sprite safariButton;
};

#endif