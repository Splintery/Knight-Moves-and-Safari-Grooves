#include "PlayerState.hpp"
#include <iostream>

PlayerState::PlayerState(ControllerDataRef data): data{data}, nbPlayers{2} {
//    Do stuff in init
}

void PlayerState::init() {
    addPlayerName.setTexture(data -> resource.getTexture("butinLaunch"));
    Vector2f center = data -> machine.getCenter();

    addPlayerName.setPosition(
        center.x - TILE_SIZE / 2, center.y + TILE_SIZE * 2
    );
    data -> resource.loadFont("Courier", "./resources/courier_std_medium.ttf");
    nameDisplay.setFont(data -> resource.getFont("Courier"));
    nameDisplay.setCharacterSize(TEXT_SIZE);
    nameDisplay.setPosition(
        center.x, center.y
    );
}

void PlayerState::handleInput() {
    Event event;

    while (data -> window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                data -> window.close();
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
        } else if (data -> input.isSpriteClicked(addPlayerName, Mouse::Left, data -> window)) {
            if ((int) playerNames.size() < nbPlayers) {
                playerNames.push_back(nameDisplay.getString());
                nameDisplay.setString("");
                replaceNameDisplay();
            }
        }
    }
}
void PlayerState::replaceNameDisplay() {
    Vector2f center = data -> machine.getCenter();

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
    data -> window.clear();
    data -> window.draw(addPlayerName);
    data -> window.draw(nameDisplay);
    Vector2f center = data -> machine.getCenter();

	RectangleShape line = RectangleShape(Vector2f(1080, 1));
	line.setPosition(center);
	data -> window.draw(line);
	line.rotate(90);
	data -> window.draw(line);
	line.rotate(90);
	data -> window.draw(line);
	line.rotate(90);
	data -> window.draw(line);

    data -> window.display();
}