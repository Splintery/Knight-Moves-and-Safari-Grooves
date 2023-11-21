#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>
// #include <SFML/Graphics.hpp> not needed because allready included in the Manager.hpp files

#include "../view/StateMachine.hpp"
#include "../view/InputManager.hpp"
#include "../view/ResourceManager.hpp"

#include "../settings/SETTINGS.hpp"

using namespace std;

struct ControllerData {
	StateMachine machine;
	RenderWindow window;
	InputManager input;
	ResourceManager resource;
};

typedef shared_ptr<ControllerData> ControllerDataRef;

class Controller {
	public:
		Controller(int width, int height, string title);
	private:
		const float dt = 1.0f / FPS;
		Clock clock;

		ControllerDataRef data = make_shared<ControllerData>();
		void run();
};
#endif