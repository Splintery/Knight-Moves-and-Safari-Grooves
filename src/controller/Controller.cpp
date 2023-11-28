#include <iostream>
#include "Controller.hpp"
#include "../view/MenuState.hpp"


Controller::Controller(int width, int height, const string& title) {
    cout << "creating window" << endl;
    machine = new StateMachine();
    input = new InputManager();
    resource = new ResourceManager();
	window = new RenderWindow(VideoMode(width, height), title);
	machine -> addState(StateRef(new MenuState(this)));

	this -> run();
}

void Controller::run() {
	float newTime, frameTime, interpolation;

	float currentTime = this -> clock.getElapsedTime().asSeconds();

	float accumulator = 0.0f;

	while (window -> isOpen()) {
		machine -> processStateChanges();

		newTime = this -> clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f) {
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt) {
			machine -> getActiveState() -> handleInput();
			machine -> getActiveState() -> update(dt);
			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		machine -> getActiveState() -> draw(interpolation);
	}
}
//void Controller::setNewGame(Game<Board, GameConfig> *newGame) {
//    if (currentGame -> isGameDone()) {
// 		currentGame = newGame;
// 	} else {
// 		cout << "Game is not finished yet" << endl;
//    }
//}