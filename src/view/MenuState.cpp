#include "MenuState.hpp"
#include "PlayerState.hpp"
#include <iostream>

using namespace std;

MenuState::MenuState(ControllerDataRef data): data{data} {
	// do stuff in init rather then here
}

void MenuState::init() {
	cout << "creating MenuState" << endl;

	data -> resource.loadTexture("butinLaunch", "./resources/ButinLaunchButton.png");
	data -> resource.loadTexture("gounkiLaunch", "./resources/GounkiLaunchButton.png");
	data -> resource.loadTexture("safariLaunch", "./resources/SafariLaunchButton.png");

	Vector2f center = data -> machine.getCenter();

	butinButton.setTexture(data -> resource.getTexture("butinLaunch"));
	gounkiButton.setTexture(data -> resource.getTexture("gounkiLaunch"));
	safariButton.setTexture(data -> resource.getTexture("safariLaunch"));

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

	while (data -> window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			data -> window.close();
		} else if (data -> input.isSpriteClicked(butinButton, Mouse::Left, data -> window)) {
            cout << "pressed buttin" << endl;
            data -> machine.addState(StateRef(new PlayerState(data)), true);
		} else if (data -> input.isSpriteClicked(gounkiButton, Mouse::Left, data -> window)) {
			cout << "pressed gounki" << endl;
		} else if (data -> input.isSpriteClicked(safariButton, Mouse::Left, data -> window)) {
			cout << "pressed safari" << endl;
		}
	}
}

void MenuState::draw(float dt) {
	data -> window.clear();

	data -> window.draw(butinButton);
	data -> window.draw(gounkiButton);
	data -> window.draw(safariButton);

//	Vector2f center = data -> machine.getCenter();

//	RectangleShape line = RectangleShape(Vector2f(1080, 1));
//	line.setPosition(center);
//	data -> window.draw(line);
//	line.rotate(90);
//	data -> window.draw(line);
//	line.rotate(90);
//	data -> window.draw(line);
//	line.rotate(90);
//	data -> window.draw(line);

	data -> window.display();
}

void MenuState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}