#include "MenuState.hpp"
#include "PlayerState.hpp"
#include <iostream>



using namespace std;

MenuState::MenuState(Controller *controller): controller{controller} {
	// do stuff in init rather then here
}

State::~State() {
    cout << "StateDestruction" << endl;
}
MenuState::~MenuState() {
    cout << "destroying menuuuuuu" << endl;
}

void MenuState::buttonFactory() {
    Sprite buttonFrameSprite = Sprite();
    Texture frameButton = Texture();
    frameButton.loadFromFile("./resources/buttonParts/ButtonFrame.png");
    buttonFrameSprite.setTexture(frameButton);
    rd.draw(buttonFrameSprite);
    Text butinText;
    butinText.setFont(controller -> resource -> getFont("pixel"));
    butinText.setString("Add");
    butinText.setStyle(Text::Bold);
    butinText.setCharacterSize(TEXT_SIZE);
    butinText.setFillColor(Color::Black);
    buttonFrameSprite.setPosition(0, 0);
    butinText.setPosition(
        buttonFrameSprite.getGlobalBounds().width / 2 - butinText.getGlobalBounds().width / 2,
        buttonFrameSprite.getGlobalBounds().height / 2 - butinText.getGlobalBounds().height / 2 - 10
    );

    Image colorBg;
    colorBg.create(240, 120, Color(61, 68, 144));
    Texture bg;
    bg.loadFromImage(colorBg);
    Sprite bgSprite;
    bgSprite.setTexture(bg);
    bgSprite.setPosition(0, 0);

    rd.create(240, 120);
    rd.clear();
    rd.draw(bgSprite);
    rd.draw(buttonFrameSprite);
    rd.draw(butinText);
    rd.display();
//    rd.getTexture().copyToImage().saveToFile("resources/button/EnabledAddButton.png");
}

void MenuState::init() {
	controller -> resource -> loadTexture("butinLaunch", "./resources/button/ButinButton.png");
    controller -> resource -> loadFont("pixel", "./resources/Minecraft.ttf");
//    buttonFactory();

	controller -> resource -> loadTexture("gounkiLaunch", "./resources/button/GounkiButton.png");
	controller -> resource -> loadTexture("safariLaunch", "./resources/button/SafariButton.png");
    controller -> resource -> loadTexture("background", "./resources/Background.png");

    butinButton.setTexture(controller -> resource -> getTexture("butinLaunch"));
	gounkiButton.setTexture(controller -> resource -> getTexture("gounkiLaunch"));
	safariButton.setTexture(controller -> resource -> getTexture("safariLaunch"));
    background.setTexture(controller -> resource -> getTexture("background"));
    gameTitle.setFont(controller -> resource -> getFont("pixel"));

    gameTitle.setString("Knight Moves and Safari Grooves");
    gameTitle.setCharacterSize(TITLE_SIZE);
    gameTitle.setFillColor(Color::Black);

    Vector2f center = controller -> machine -> getCenter();

	gounkiButton.setPosition(
		center.x - gounkiButton.getGlobalBounds().width / 2, center.y - TILE_SIZE / 2
	);
	butinButton.setPosition(
		center.x - butinButton.getGlobalBounds().width * 1.5 - TILE_SIZE, center.y - TILE_SIZE / 2
	);
	safariButton.setPosition(
		center.x + safariButton.getGlobalBounds().width / 2 + TILE_SIZE, center.y - TILE_SIZE / 2
	);
    background.setPosition(0, 0);
    gameTitle.setPosition(
        center.x - gameTitle.getGlobalBounds().width / 2, TILE_SIZE * 6
    );
}

void MenuState::handleInput() {
	Event event;

	while (controller -> window -> pollEvent(event)) {
		if (event.type == Event::Closed) {
			controller -> window -> close();
		} else if (controller -> canStartNewGame()) {
            if (controller -> input -> isSpriteClicked(butinButton, Mouse::Left, *controller -> window)) {
                cout << "pressed buttin" << endl;
                controller -> setNewGame(new Butin(), "butin");
                cout << "in menuState going to player...\n";
                controller -> machine -> addState(new PlayerState(controller), false);
            } else if (controller -> input -> isSpriteClicked(gounkiButton, Mouse::Left, *controller -> window)) {
                cout << "pressed gounki" << endl;
            } else if (controller -> input -> isSpriteClicked(safariButton, Mouse::Left, *controller -> window)) {
                cout << "pressed safari" << endl;
            }
        }

	}
}

void MenuState::draw() {
	controller -> window -> clear();
    controller -> window -> draw(background);
    controller -> window -> draw(gameTitle);

	controller -> window -> draw(butinButton);
	controller -> window -> draw(gounkiButton);
	controller -> window -> draw(safariButton);

    Sprite tmp;
    tmp.setTexture(rd.getTexture());
    tmp.setPosition(250, 250);
    controller -> window -> draw(tmp);

	controller -> window -> display();
}

void MenuState::update() {
	// std::cout << "updating the menu" << std::endl;
}