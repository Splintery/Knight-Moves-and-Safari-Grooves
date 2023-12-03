#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include "../controller/Controller.hpp"

class PlayerState: public State {
    public:
        PlayerState(Controller *controller);
        virtual ~PlayerState();
		void init();
		void handleInput();
		void update();
		void draw();
    private:
        Controller *controller;
        const int minPlayers;
        const int maxPlayers;
        vector<string> playerNames;
        Sprite addPlayerButton;
        Sprite startButton;
        Text title;
        vector<Text> playerDisplayNames;
        void repositionNameDisplay();
        void goToGameState();
        void saveName();
};

#endif