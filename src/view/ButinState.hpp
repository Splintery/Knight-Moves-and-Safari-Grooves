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
        Text currentPlayer;

        vector<Vector2i> piecesToRemove;
        Sprite displayPiecesToRemove;

        RenderTexture rd;
        void boardFactory();
		Vector2i fromTile;
		Vector2i toTile;
		bool moveReady;
        void buildPieces(vector<vector<vector<string>>> sprites);
        void addPieceToRemove(Vector2i v);
};

#endif