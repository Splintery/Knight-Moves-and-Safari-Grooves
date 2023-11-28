#include <iostream>
#include "PlayerState.hpp"

PlayerState::PlayerState(Controller *controller): controller{controller}, nbPlayers{2} {
    playerDisplayNames.insert(playerDisplayNames.begin(), Text());
    //Do stuff in init
}

void PlayerState::init() {
    title.setFont(controller -> resource -> getFont("pixel"));
    playerDisplayNames[0].setFont(controller -> resource -> getFont("pixel"));
    background.setTexture(controller -> resource -> getTexture("background"));
    addPlayerNameButton.setTexture(controller -> resource -> getTexture("butinLaunch"));

    Vector2f center = controller -> machine -> getCenter();

    background.setPosition(0, 0);
    addPlayerNameButton.setPosition(
        center.x - addPlayerNameButton.getGlobalBounds().width / 2, center.y + addPlayerNameButton.getGlobalBounds().height * 2
    );

    title.setCharacterSize(TITLE_SIZE);
    title.setFillColor(Color::Black);
    title.setString("Enter the names of the 2 players");
    title.setPosition(
        center.x - title.getGlobalBounds().width / 2, center.y - TILE_SIZE * 5
    );

    playerDisplayNames[0].setCharacterSize(TEXT_SIZE);
    playerDisplayNames[0].setFillColor(Color::Black);
    playerDisplayNames[0].setString("");
}

void PlayerState::handleInput() {
    Event event{};

    while (controller -> window -> pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                controller -> window -> close();
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13) {
                    playerDisplayNames[0].setString(
                        playerDisplayNames[0].getString() + (char)event.text.unicode
                    );
                    repositionNameDisplay();
                }
                break;
            case sf::Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
                    playerDisplayNames[0].setString(
                        playerDisplayNames[0].getString().substring(0, playerDisplayNames[0].getString().getSize() - 1)
                    );
                    repositionNameDisplay();
                } else if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    saveName();
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (controller -> input -> isSpriteClicked(addPlayerNameButton, Mouse::Left, *controller -> window)) {
                    saveName();
                }

            default:
                break;
        }
    }
}
void PlayerState::saveName() {
    if ((int) playerNames.size() < nbPlayers && playerDisplayNames[0].getString().getSize() > 0) {
        playerNames.push_back(playerDisplayNames[playerDisplayNames.size() - 1].getString());
        playerDisplayNames.insert(playerDisplayNames.begin(), Text());
        playerDisplayNames[0].setFont(controller -> resource -> getFont("pixel"));
        playerDisplayNames[0].setCharacterSize(TEXT_SIZE);
        playerDisplayNames[0].setFillColor(Color::Black);
        playerDisplayNames[0].setString("");
        repositionNameDisplay();
    }
}

void PlayerState::repositionNameDisplay() {
    Vector2f center = controller -> machine -> getCenter();

    for (int i = 0; i < (int) playerDisplayNames.size(); i++) {
        playerDisplayNames[i].setPosition(
            center.x - playerDisplayNames[i].getGlobalBounds().width / 2, center.y - (TILE_SIZE * i)
        );
    }
}

void PlayerState::update(float dt) {
//    No Special updates for Player initilisation State
}

void PlayerState::draw(float dt) {
    controller -> window -> clear();

    controller -> window -> draw(background);
    controller -> window -> draw(title);
    controller -> window -> draw(addPlayerNameButton);
    for (Text t : playerDisplayNames) {
        controller -> window -> draw(t);
    }
    controller -> window -> display();
}