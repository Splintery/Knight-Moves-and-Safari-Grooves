#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class State {
	public:
        virtual ~State();
		virtual void init() = 0;
		virtual void handleInput() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void pause() {}
		virtual void resume() {}
        bool isPaused = false;
    protected:
        sf::Sprite background;
};

#endif