#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>

#include "../view/StateMachine.hpp"
#include "../view/InputManager.hpp"
#include "../view/ResourceManager.hpp"

#include "../settings/SETTINGS.hpp"
#include "../model/Game.hpp"
#include "../model/butin/Butin.hpp"
#include "../model/safari/Safari.hpp"
#include "../model/GameConfig.hpp"


using namespace std;

class Controller {
	public:
		Controller(int width, int height, const string& title);
        StateMachine *machine;
        RenderWindow *window;
        InputManager *input;
        ResourceManager *resource;
        Game *game;

        void setNewGame(Game *, string name);
        bool canStartNewGame() const;
        string getGameName() const;
        void setPlayerNames(vector<string> newNames);
	private:
        // 100000.0 représente 1 seconde en micro seconde
        const float timePerUpdate = 1000000.0 / UPS;
        const float timePerFrame = 1000000.0 / FPS;
		Clock clock;

        string gameName = "";
        vector<string> playerNames;
        void loadTextures() const;
        void run();
};
#endif