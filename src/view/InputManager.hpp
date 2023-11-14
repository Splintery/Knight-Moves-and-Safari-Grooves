#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager {
	public:
		InputManager() {}
		virtual ~InputManager() {}

		bool isSpriteClicked(Sprite sp, Mouse::Button mButton, RenderWindow &window);
		Vector2f getMousePosition(sf::RenderWindow &window);
};