#include "ButinState.hpp"
#include <iostream>

using namespace std;

ButinState::ButinState(ControllerDataRef data): data{data} {
	// do stuff in init rather then here
}

void ButinState::init() {
	
}

void ButinState::handleInput() {
	Event event;

	while (data -> window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			data -> window.close();
		} else if (data -> input.isSpriteClicked(butinButton, Mouse::Left, data -> window)) {
			cout << "pressed buttin" << endl;
		} else if (data -> input.isSpriteClicked(gounkiButton, Mouse::Left, data -> window)) {
			cout << "pressed gounki" << endl;
		} else if (data -> input.isSpriteClicked(safariButton, Mouse::Left, data -> window)) {
			cout << "pressed safari" << endl;
		}
	}
}

void ButinState::draw(float dt) {
	data -> window.clear();



	data -> window.display();
}

void ButinState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}