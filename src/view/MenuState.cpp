#include "MenuState.hpp"
#include "PlayerState.hpp"
#include <iostream>

using namespace std;

MenuState::MenuState(Controller *controller): controller{controller} {
	// do stuff in init rather then here
}

void MenuState::init() {
	cout << "creating MenuState" << endl;

	controller -> resource -> loadTexture("butinLaunch", "./resources/ButinLaunchButton.png");
	controller -> resource -> loadTexture("gounkiLaunch", "./resources/GounkiLaunchButton.png");
	controller -> resource -> loadTexture("safariLaunch", "./resources/SafariLaunchButton.png");

	Vector2f center = controller -> machine -> getCenter();

	butinButton.setTexture(controller -> resource -> getTexture("butinLaunch"));
	gounkiButton.setTexture(controller -> resource -> getTexture("gounkiLaunch"));
	safariButton.setTexture(controller -> resource -> getTexture("safariLaunch"));

	gounkiButton.setPosition(
		center.x - TILE_SIZE, center.y - TILE_SIZE / 2
	);
	butinButton.setPosition(
		center.x - TILE_SIZE * 4, center.y - TILE_SIZE / 2
	);
	safariButton.setPosition(
		center.x + TILE_SIZE * 2, center.y - TILE_SIZE / 2
	);
}

// {
// 	if (Keyboard::isKeyPressed(Keyboard::Right))
// 		testButton.move(1, 0);
// 	if (Keyboard::isKeyPressed(Keyboard::Left))
// 		testButton.move(-1, 0);
// 	 if (Keyboard::isKeyPressed(Keyboard::Up))
// 		testButton.move(0, -1);
// 	if (Keyboard::isKeyPressed(Keyboard::Down))
// 		testButton.move(0, 1);
// }

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

	controller -> window -> draw(butinButton);
	controller -> window -> draw(gounkiButton);
	controller -> window -> draw(safariButton);

//	Vector2f center = controller -> machine -> getCenter();

//	RectangleShape line = RectangleShape(Vector2f(1080, 1));
//	line.setPosition(center);
//	controller -> window -> draw(line);
//	line.rotate(90);
//	controller -> window -> draw(line);
//	line.rotate(90);
//	controller -> window -> draw(line);
//	line.rotate(90);
//	controller -> window -> draw(line);

	controller -> window -> display();
}

void MenuState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}