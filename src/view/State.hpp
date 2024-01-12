#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

/**
 * La classe mère de tout les différents états que peut prendre notre logiciel
 * dans notre cas, un état est l'équivalent d'un JPanel en swing
 * */
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