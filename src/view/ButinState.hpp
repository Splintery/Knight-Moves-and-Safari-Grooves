#ifndef BUTINSTATE_H
#define BUTINSTATE_H

#include "../controller/Controller.hpp"
// #include <array>

using namespace sf;

class ButinState: public State {
	public:
		ButinState(Controller *controller);
        virtual ~ButinState();
		void init();
		void handleInput();
		void update();
		void draw();
	private:
		Controller *controller;

		vector<vector<vector<string>>> pieces;
        Sprite board;
        Sprite *pieceSprite;
        Text currentPlayerDisplay;
        Text currentPlayerScoreDisplay;

        // Those 2 fields are only ever used for the gameConfig to be built and displayed
        vector<Vector2i> piecesToRemove;
        Sprite redTileSprite;

        RenderTexture rd;
        void boardFactory();

        Sprite blueTileSprite;
		Vector2i *fromTile = nullptr;
		Vector2i *toTile = nullptr;
        vector<Vector2i> movesPossible;
		bool moveReady;
        bool playerPlayed;

        void addPieceToRemove(Vector2i v);
        void positionRedTile(Vector2i v);
        void positionBlueTile(Vector2i v);

};

#endif