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
        void positionPieceWithinBoard(Sprite *piece, Vector2i pos, int offset);
};


#endif
