#ifndef BUTINSTATE_H
#define BUTINSTATE_H

#include "GameState.hpp"

using namespace sf;

class ButinState: public GameState {
	public:
		ButinState(Controller *controller);
        ~ButinState();
		void init();
		void handleInput();
		void update();
		void draw();
	private:
        void boardFactory();
        Texture& backBoardFactory();
        vector<Vector2i> piecesToRemove;
        void addPieceToRemove(Vector2i v);
        Text initInstructions;

};

#endif