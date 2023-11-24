#include "PlayerState.hpp"
#include <iostream>

PlayerState::PlayerState(ControllerDataRef data): data{data}, nbPlayers{2} {
//    Do stuff in init
}

void PlayerState::init() {
    addPlayerName.setTexture(data -> resource.getTexture("butinLaunch"));
    Vector2f center = data -> machine.getCenter();

    addPlayerName.setPosition(
        center.x, center.y - TILE_SIZE * 2
    );
    data -> resource.loadFont("Courier", "./resources/courier_std_medium.ttf");
    nameDisplay.setFont(data -> resource.getFont("Courier"));
    nameDisplay.setCharacterSize(48);
    nameDisplay.setStyle(Text::Bold);
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
                }
                break;
            default:
                break;
        }
        if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
            nameDisplay.setString(nameDisplay.getString().substring(0, nameDisplay.getString().getSize() - 1));
        } else if (data -> input.isSpriteClicked(addPlayerName, Mouse::Left, data -> window)) {
            if ((int) playerNames.size() <= nbPlayers) {
                playerNames.push_back(nameDisplay.getString());
                nameDisplay.setString("");
            }
        }
    }
}

void PlayerState::update(float dt) {
//    No Special updates for Player initilisation State
}

void PlayerState::draw(float dt) {
    data -> window.clear();
    data -> window.draw(addPlayerName);
    data -> window.draw(nameDisplay);
    data -> window.display();
}