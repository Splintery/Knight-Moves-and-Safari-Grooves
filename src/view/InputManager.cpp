#include "InputManager.hpp"

bool InputManager::isSpriteClicked(Sprite sp, Mouse::Button mButton, RenderWindow &window) {
	if (Mouse::isButtonPressed(mButton)) {
		if (sp.getGlobalBounds().contains(getMousePosition(window))) {
			return true;
		}
	}
	return false;
}
Vector2f InputManager::getMousePosition(RenderWindow &window) {
	Vector2i tmp = Mouse::getPosition(window);
	Vector2f v(tmp.x, tmp.y);
	return v;
}
Vector2i InputManager::getTileWithinBoard(Sprite board, Vector2f mousePos, int boardSize) {
    return Vector2i{
            (int) ((mousePos.x - board.getGlobalBounds().left) / (board.getGlobalBounds().width / boardSize)),
            (int) ((mousePos.y  - board.getGlobalBounds().top) / (board.getGlobalBounds().height / boardSize))
    };
}
void InputManager::positionPieceWithinBoard(sf::Sprite *piece, sf::Sprite board, Vector2i pos, int boardSize) {
    int tileWidth = board.getGlobalBounds().width / boardSize;
    int tileHeight = board.getGlobalBounds().height / boardSize;
    piece -> setPosition(
        pos.x * tileWidth + board.getGlobalBounds().left + (tileWidth / 2 - piece -> getGlobalBounds().width / 2),
        pos.y * tileHeight + board.getGlobalBounds().top + (tileHeight / 2 - piece -> getGlobalBounds().height / 2)
    );
}