#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "../controller/Controller.hpp"

class PauseState : public State {
public:
    PauseState(Controller *controller, Texture *texture);
    virtual  ~PauseState();
    PauseState(const PauseState&) = delete;
    PauseState& operator=(const PauseState&) = delete;

    void init();
    void handleInput();
    void update();
    void draw();
private:
    Controller *controller;
    Texture backgroundTexture;
    Sprite resumeButton;
    Sprite returnMenuButton;
    Sprite exitButton;
};

#endif