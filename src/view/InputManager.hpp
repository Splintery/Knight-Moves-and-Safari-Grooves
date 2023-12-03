#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager {
	public:
		InputManager() {}
		virtual ~InputManager() {}

		bool isSpriteClicked(Sprite sp, Mouse::Button mButton, RenderWindow &window);
		Vector2f getMousePosition(RenderWindow &window);
        Vector2i getTileWithinBoard(Sprite board, Vector2f mousePos, int boardSize);
        void positionPieceWithinBoard(Sprite *piece, Sprite board, Vector2i pos, int boardSize);
};

#endif