#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>

#include "../view/StateMachine.hpp"
#include "../view/InputManager.hpp"
#include "../view/ResourceManager.hpp"

#include "../settings/SETTINGS.hpp"
#include "../model/Game.hpp"
//#include "../model/Board.hpp"
//#include "../model/GameConfig.hpp"
//#include "../utilities/Utilities.hpp"


using namespace std;

class Controller {
	public:
		Controller(int width, int height, const string& title);
        StateMachine *machine;
        RenderWindow *window;
        InputManager *input;
        ResourceManager *resource;

	private:
		const float dt = 1.0f / FPS;
		Clock clock;

        void run();
//		 void setNewGame(Game *newGame);
};
#endif