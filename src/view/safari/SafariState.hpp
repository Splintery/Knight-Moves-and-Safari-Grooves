#ifndef SAFARISTATE_HPP
#define SAFARISTATE_HPP

#include "../GameState.hpp"

class SafariState : public GameState {
    public:
		SafariState(Controller *controller);
        ~SafariState();
		void init();
		void handleInput();
		void update();
		void draw();
	private:
        void boardFactory();
        Texture& backBoardFactory();

        vector<Vector2i> crocodilesToAdd;
        void addCrocodile(Vector2i v);
        vector<Vector2i> elephantsToAdd;
        void addElephant(Vector2i v);
        vector<Vector2i> lionsToAdd;
        void addLion(Vector2i v);
        vector<Vector2i> fencesToAdd;
        void addFence(Vector2i v);
        Text initInstructions;
};


#endif
