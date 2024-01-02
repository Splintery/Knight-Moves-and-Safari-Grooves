#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../controller/Controller.hpp"

using namespace sf;

class MenuState: public State {
	public:
		MenuState(Controller *controller);
        virtual ~MenuState();
		void init();
		void handleInput();
		void update();
		void draw();
	private:
		Controller *controller;

        Text gameTitle;
		Sprite butinButton;
		Sprite gounkiButton;
		Sprite safariButton;

        RenderTexture rd;
        void buttonFactory();
};

#endif