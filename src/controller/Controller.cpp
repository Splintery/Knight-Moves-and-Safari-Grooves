#include "Controller.hpp"
#include "../view/MenuState.hpp"

Controller::Controller(int width, int height, string title) {
	data -> window.create(VideoMode(width, height), title);
	data -> machine.addState(StateRef(new MenuState(data)));

	this -> run();
}

void Controller::run() {
	float newTime, frameTime, interpolation;

	float currentTime = this -> clock.getElapsedTime().asSeconds();

	float accumulator = 0.0f;

	while (data -> window.isOpen()) {
		this -> data -> machine.processStateChanges();

		newTime = this -> clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			this -> data -> machine.getActiveState() -> handleInput();
			this -> data -> machine.getActiveState() -> update(dt);
			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this -> data -> machine.getActiveState() -> draw(interpolation);
	}
}