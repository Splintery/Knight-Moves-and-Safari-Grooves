#include "MenuState.hpp"
#include <iostream>

using namespace std;

MenuState::MenuState(ControllerDataRef data): data{data} {
	// do stuff in init rather then here
}

void MenuState::init() {
	cout << "creating MenuState" << endl;
	Texture texture;
	texture.loadFromFile("./resources/TmpButton.png");
	testButton.setTexture(texture);
	testButton.setPosition(400.0f, 400.0f);
	cout << "x: " << texture.getSize().x << endl;
	cout << "y: " << texture.getSize().y << endl;
}

void MenuState::handleInput() {
	Event event;

	while (data -> window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			data -> window.close();
		} else if (data -> input.isSpriteClicked(testButton, Mouse::Left, data -> window)) {
			cout << "pressed" << endl;
			testButton.setPosition(0.0f, 0.0f);
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
		testButton.move(1, 0);
	if (Keyboard::isKeyPressed(Keyboard::Left))
		testButton.move(-1, 0);
	 if (Keyboard::isKeyPressed(Keyboard::Up))
		testButton.move(0, -1);
	if (Keyboard::isKeyPressed(Keyboard::Down))
		testButton.move(0, 1);

}

void MenuState::draw(float dt) {
	data -> window.clear();
	// std::cout << "drawingg!!!!" << std::endl;
	// std::cout << testButton.getTexture() -> getSize() << std::endl;
	data -> window.draw(testButton);
	data -> window.display();
}

void MenuState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}