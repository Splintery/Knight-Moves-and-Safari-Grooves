#pragma once
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "../view/StateMachine.hpp"
#include "../view/InputManager.hpp"
#include "../settings/SETTINGS.hpp"

using namespace std;

struct ControllerData {
	StateMachine machine;
	RenderWindow window;
	InputManager input;
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