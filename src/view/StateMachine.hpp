#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>

#include "State.hpp"


typedef std::unique_ptr<State> StateRef;

class StateMachine {
	public:
		StateMachine() = default;
		virtual ~StateMachine() = default;
		void addState(StateRef newState, bool isReplacing = true);
		void removeState();
		void processStateChanges();
		sf::Vector2f getCenter();

		StateRef &getActiveState();
	private:
		std::stack<StateRef> states;
		StateRef newState;
		
		bool isRemoving = false;
		bool isAdding = false;
		bool isReplacing = false;
};

#endif