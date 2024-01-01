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