#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../controller/Controller.hpp"

using namespace sf;

class MenuState: public State {
	public:
		MenuState(Controller *controller);
		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
	private:
		Controller *controller;
		Clock clock;

        Text gameTitle;
		Sprite butinButton;
		Sprite gounkiButton;
		Sprite safariButton;

        RenderTexture rd;
        void buttonFactory();
};

#endif