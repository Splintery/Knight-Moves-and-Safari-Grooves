#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "../controller/Controller.hpp"

using namespace sf;

class MenuState: public State {
public:
    MenuState(Controller *controller);
    virtual ~MenuState();
    MenuState(const MenuState &) = delete;
    MenuState &operator=(const MenuState &) = delete;

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

    Sprite closeButton;
    Sprite quitButin;
    Sprite quitGounki;
    Sprite quitSafari;

    RenderTexture rd;
    void buttonFactory();
};

#endif