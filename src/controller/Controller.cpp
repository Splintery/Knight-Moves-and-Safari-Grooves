#include <iostream>
#include "Controller.hpp"
#include "../view/MenuState.hpp"


Controller::Controller(int width, int height, const string& title) {
    cout << "creating window" << endl;
    machine = new StateMachine();
    input = new InputManager();
    resource = new ResourceManager();

	window = new RenderWindow(VideoMode(width, height), title, Style::Fullscreen | Style::Resize | Style::Close);
    sf::Mouse::setPosition(Vector2i(0, 0), *window);


    machine -> addState(new MenuState(this));
    game = nullptr;

    clock = Clock();

    loadTextures();

	this -> run();
}

void Controller::loadTextures() const {
    resource -> loadTexture("enabledStartButton", "./resources/button/EnabledStartButton.png");
    resource -> loadTexture("disabledStartButton", "./resources/button/DisabledStartButton.png");
    resource -> loadTexture("enabledAddButton", "./resources/button/EnabledAddButton.png");
    resource -> loadTexture("disabledAddButton", "./resources/button/DisabledAddButton.png");
    resource -> loadTexture("yellowPiece", "./resources/piece/YellowPiece.png");
    resource -> loadTexture("redPiece", "./resources/piece/RedPiece.png");
    resource -> loadTexture("blackPiece", "./resources/piece/BlackPiece.png");
    resource -> loadTexture("redTile", "./resources/board/RedTile.png");
    resource -> loadTexture("blueTile", "./resources/board/BlueTile.png");

}

void Controller::run() {
    int updates = 0;
    double updateTracker = 0;

    int frames = 0;
    double frameTracker = 0;

    long lastCheck = clock.getElapsedTime().asMilliseconds();
    long previousTime = clock.getElapsedTime().asMicroseconds();

    while (window -> isOpen()) {
        machine -> processStateChanges();
        long currentTime = clock.getElapsedTime().asMicroseconds();

        updateTracker += (currentTime - previousTime) / timePerUpdate;
        if (updateTracker >= 1) {
            if (!machine -> getActiveState() -> isPaused) {
                machine -> getActiveState() -> handleInput();
                machine -> getActiveState() -> update();
                updates++;
            }
            updateTracker--;
        }
        frameTracker += (currentTime - previousTime) / timePerFrame;
        if (frameTracker >= 1) {
            machine -> getActiveState() -> draw();

            frames++;
            frameTracker--;
        }

        if (clock.getElapsedTime().asMilliseconds() - lastCheck >= 1000) {
            lastCheck = clock.getElapsedTime().asMilliseconds();
//            cout << "FPS: " << frames << "\nUPS: " << updates << endl;
            updates = 0;
            frames = 0;
        }
        previousTime = currentTime;
    }
}

bool Controller::canStartNewGame() const {
    return game == nullptr || game -> isGameDone();
}

// Les vérifs necessaires seront faites avant d'appeler setNewGame
void Controller::setNewGame(Game *newGame, string name) {
    gameName = name;
    game = newGame;
}
void Controller::setPlayerNames(vector<std::string> newNames) {
    playerNames = newNames;
}

string Controller::getGameName() const {
    return gameName;
}