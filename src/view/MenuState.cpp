#include "MenuState.hpp"
#include "PlayerState.hpp"
#include <iostream>

using namespace std;

MenuState::MenuState(Controller *controller): controller{controller} {
	// do stuff in init rather then here
}

void MenuState::init() {
	controller -> resource -> loadTexture("butinLaunch", "./resources/ButinLaunchButton.png");
	controller -> resource -> loadTexture("gounkiLaunch", "./resources/GounkiLaunchButton.png");
	controller -> resource -> loadTexture("safariLaunch", "./resources/SafariLaunchButton.png");
    controller -> resource -> loadTexture("background", "./resources/TmpBackground.png");
    controller -> resource -> loadFont("pixel", "./resources/Minecraft.ttf");

    butinButton.setTexture(controller -> resource -> getTexture("butinLaunch"));
	gounkiButton.setTexture(controller -> resource -> getTexture("gounkiLaunch"));
	safariButton.setTexture(controller -> resource -> getTexture("safariLaunch"));
    background.setTexture(controller -> resource -> getTexture("background"));
    gameTitle.setFont(controller -> resource -> getFont("pixel"));

    gameTitle.setString("Knight Moves and Safari Grooves");
    gameTitle.setCharacterSize(TITLE_SIZE);
    gameTitle.setFillColor(Color::Black);

    Vector2f center = controller -> machine -> getCenter();

	gounkiButton.setPosition(
		center.x - TILE_SIZE, center.y - TILE_SIZE / 2
	);
	butinButton.setPosition(
		center.x - TILE_SIZE * 4, center.y - TILE_SIZE / 2
	);
	safariButton.setPosition(
		center.x + TILE_SIZE * 2, center.y - TILE_SIZE / 2
	);
    background.setPosition(0, 0);
    gameTitle.setPosition(
        center.x - gameTitle.getGlobalBounds().width / 2, TILE_SIZE * 6
    );
}

void MenuState::handleInput() {
	Event event;

	while (controller -> window -> pollEvent(event)) {
		if (event.type == Event::Closed) {
			controller -> window -> close();
		} else if (controller -> input -> isSpriteClicked(butinButton, Mouse::Left, *controller -> window)) {
            cout << "pressed buttin" << endl;
            controller -> machine -> addState(StateRef(new PlayerState(controller)), true);
		} else if (controller -> input -> isSpriteClicked(gounkiButton, Mouse::Left, *controller -> window)) {
			cout << "pressed gounki" << endl;
		} else if (controller -> input -> isSpriteClicked(safariButton, Mouse::Left, *controller -> window)) {
			cout << "pressed safari" << endl;
		}
	}
}

void MenuState::draw(float dt) {
	controller -> window -> clear();
    controller -> window -> draw(background);
    controller -> window -> draw(gameTitle);

	controller -> window -> draw(butinButton);
	controller -> window -> draw(gounkiButton);
	controller -> window -> draw(safariButton);

	controller -> window -> display();
}

void MenuState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}