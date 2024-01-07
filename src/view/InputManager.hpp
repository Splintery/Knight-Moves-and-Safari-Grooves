#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager {
public:
    InputManager() {}
    virtual ~InputManager() {}
    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;

    bool isSpriteClicked(Sprite sp, Mouse::Button mButton, RenderWindow &window);
    Vector2f getMousePosition(RenderWindow &window);
};

#endif