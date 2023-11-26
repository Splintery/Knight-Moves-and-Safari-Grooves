#include "PlayerState.hpp"

PlayerState::PlayerState(Controller *controller): controller{controller}, nbPlayers{2} {
//    Do stuff in init
}

void PlayerState::init() {
    addPlayerName.setTexture(controller -> resource -> getTexture("butinLaunch"));
    Vector2f center = controller -> machine -> getCenter();

    addPlayerName.setPosition(
        center.x - TILE_SIZE / 2, center.y + TILE_SIZE * 2
    );
    controller -> resource -> loadFont("Courier", "./resources/courier_std_medium.ttf");
    nameDisplay.setFont(controller -> resource -> getFont("Courier"));
    nameDisplay.setCharacterSize(TEXT_SIZE);
    nameDisplay.setPosition(
        center.x, center.y
    );
}

void PlayerState::handleInput() {
    Event event{};

    while (controller -> window -> pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                controller -> window -> close();
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {
                    nameDisplay.setString(nameDisplay.getString() + (char)event.text.unicode);
                    replaceNameDisplay();
                }
                break;
            default:
                break;
        }
        if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
            nameDisplay.setString(nameDisplay.getString().substring(0, nameDisplay.getString().getSize() - 1));
            replaceNameDisplay();
        } else if (controller -> input -> isSpriteClicked(addPlayerName, Mouse::Left, *controller -> window)) {
            if ((int) playerNames.size() < nbPlayers) {
                playerNames.push_back(nameDisplay.getString());
                nameDisplay.setString("");
                replaceNameDisplay();
            }
        }
    }
}
void PlayerState::replaceNameDisplay() {
    Vector2f center = controller -> machine -> getCenter();

    float offset = nameDisplay.getGlobalBounds().width;

    nameDisplay.setPosition(
        center.x - offset / 2,
        center.y
    );
}

void PlayerState::update(float dt) {
//    No Special updates for Player initilisation State
}

void PlayerState::draw(float dt) {
    controller -> window -> clear();
    controller -> window -> draw(addPlayerName);
    controller -> window -> draw(nameDisplay);
    Vector2f center = controller -> machine -> getCenter();

	RectangleShape line = RectangleShape(Vector2f(1080, 1));
	line.setPosition(center);
	controller -> window -> draw(line);
	line.rotate(90);
	controller -> window -> draw(line);
	line.rotate(90);
	controller -> window -> draw(line);
	line.rotate(90);
	controller -> window -> draw(line);

    controller -> window -> display();
}