#ifndef GOUNKISTATE_HPP
#define GOUNKISTATE_HPP

#include "../GameState.hpp"

class GounkiState: public GameState {
    public :
        GounkiState(Controller *controller);
        ~GounkiState();
        void init();
        void handleInput();
        void update();
        void draw();
    private:
        void boardFactory();
        void drawPieces();
};


#endif
