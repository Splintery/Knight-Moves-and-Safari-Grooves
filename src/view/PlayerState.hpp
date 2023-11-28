#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include "../controller/Controller.hpp"

class PlayerState: public State {
    public:
        PlayerState(Controller *controller);
		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);
    private:
        Controller *controller;
        const int nbPlayers;
        vector<string> playerNames;
        Sprite addPlayerNameButton;
        Text title;
        vector<Text> playerDisplayNames;
        void repositionNameDisplay();
        void saveName();
};

#endif