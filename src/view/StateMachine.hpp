#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;

class StateMachine {
	public:
		StateMachine() {}
		virtual ~StateMachine() {}
		void addState( StateRef newState, bool isReplacing = true);
		void removeState();
		void processStateChanges();

		StateRef &getActiveState();
	private:
		std::stack<StateRef> states;
		StateRef newState;
		
		bool isRemoving;
		bool isAdding;
		bool isReplacing;
};

#endif