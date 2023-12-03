#include "StateMachine.hpp"
#include "../settings/SETTINGS.hpp"
#include <iostream>

void StateMachine::addState(State *newState, bool isReplacing) {
	this -> isAdding = true;
	this -> isReplacing = isReplacing;
	this -> newState = std::move(newState);
}
void StateMachine::removeState() {
	isRemoving = true;
}

void StateMachine::processStateChanges() {
	if (isRemoving && !states.empty()) {
        delete(states.top());
        states.pop();
		if (!states.empty()) {
			states.top() -> resume();
		}

		isRemoving = false;
	}
	if (isAdding) {
		if (!states.empty()) {
			if (isReplacing) {
				states.pop();
			} else {
				states.top() -> pause();
			}
		}

		states.push(std::move(newState));
		states.top() -> init();
		isAdding = false;
	}
}

State *StateMachine::getActiveState() {
	return states.top();
}

sf::Vector2f StateMachine::getCenter() {
	sf::Vector2f v{SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
	return v;
}