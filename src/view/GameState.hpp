#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../controller/Controller.hpp"

using namespace sf;

class GameState: public State {
    public:
        virtual ~GameState();
        virtual void init() = 0;
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void pause() {}
        virtual void resume() {}
    protected:
        GameState(Controller *controller);
        Controller *controller;

        // boolean values used by update() and handleInput() to communicate
        bool moveReady;
        bool playerPlayed;
        bool printWinner;

        // column x lines x number of pieces on that tile
        // & string holds the name of the piece
        vector<vector<vector<string>>> pieces;
        Sprite board;
        Sprite backBoard;
        void drawBase();
        // one Sprite will have its texture changed and position replaced to draw all the pieces
        // insted of having a sprite for each of the pieces on the board
        Sprite *pieceSprite = nullptr;
        virtual void drawPieces() = 0;

        int currentPlayerIndex;
        vector<Text> playerNamesDisplay;
        vector<Text> playerScoresDisplay;
        void updateScoresDisplay();
        // x is the offeset on where to draw it on the window
        void initializePlayerDisplay(int x);
        void drawPlayerDisplay();
        void colorCurrentPlayer();

        // used to show the possibles moves a certain piece can make
        Sprite redTileSprite;
        void positionRedTile(Vector2i v);
        // used to show wich piece is being selected
        Sprite blueTileSprite;
        void positionBlueTile(Vector2i v);
        void drawSelectedTile();

        // those two will be used in the init() to build a big Sprite for the board from multiple images of a Tile
        RenderTexture render;
        virtual void boardFactory() = 0;
        virtual Texture& backBoardFactory() = 0;

        Vector2i *fromTile = nullptr;
        Vector2i *toTile = nullptr;
        vector<Vector2i> movesPossible;
        void drawMovesPossible();

        // will be displayed on the screen when the game is finished (printWinner = true)
        Text winner;
        void gameOver();

};

#endif
