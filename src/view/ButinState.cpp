#include "ButinState.hpp"

using namespace std;

ButinState::ButinState(Controller *controller): controller{controller} {
	// do stuff in init rather then here
}

void ButinState::init() {
	
}

void ButinState::handleInput() {
	Event event;

	while (controller -> window -> pollEvent(event)) {
		if (event.type == Event::Closed) {
			controller -> window -> close();
		// } else if (controller -> input.isSpriteClicked(butinButton, Mouse::Left, controller -> window)) {
		// 	cout << "pressed buttin" << endl;
		// } else if (controller -> input.isSpriteClicked(gounkiButton, Mouse::Left, controller -> window)) {
		// 	cout << "pressed gounki" << endl;
		// } else if (controller -> input.isSpriteClicked(safariButton, Mouse::Left, controller -> window)) {
		// 	cout << "pressed safari" << endl;
		}
	}
}

void ButinState::draw(float dt) {
	controller -> window -> clear();



	controller -> window -> display();
}

void ButinState::update(float dt) {
	// std::cout << "updating the menu" << std::endl;
}