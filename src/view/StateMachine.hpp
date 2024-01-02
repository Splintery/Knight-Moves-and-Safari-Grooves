#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>

#include "State.hpp"


class StateMachine {
	public:
		StateMachine() = default;
		virtual ~StateMachine() = default;
		void addState(State *newState, bool isReplacing = true);
		void removeState();
		void processStateChanges();


		sf::Vector2f getCenter();

		State *getActiveState();
        std::stack<State *> states;
		State *newState;
		
		bool isRemoving = false;
		bool isAdding = false;
		bool isReplacing = false;
};

#endif