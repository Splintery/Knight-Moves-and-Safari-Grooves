#include "GameState.hpp"

GameState::GameState(Controller *controller): controller{controller}, moveReady{false}, playerPlayed{false}, printWinner{false}, currentPlayerIndex{controller -> game -> getCurrentPlayerIndex()} {
    // Do stuff in init()
}
GameState::~GameState() {
    cout << "deleting gamestate" << endl;
}

void GameState::drawBase() {
    controller -> window -> draw(background);
    controller -> window -> draw(backBoard);
    controller -> window -> draw(board);
}
void GameState::updateScoresDisplay() {
    vector<string> newScores = ((Butin *) controller -> game) -> getPlayerScores();
    for (size_t i = 0; i < playerScoresDisplay.size(); i++) {
        playerScoresDisplay[i].setString(newScores[i]);
    }
}

void GameState::initializePlayerDisplay(int x) {
    for (size_t i = 0; i < controller -> game -> getPlayerNames().size(); i++) {
        playerNamesDisplay.push_back(Text());
        playerNamesDisplay[i].setFont(controller -> resource -> getFont("pixel"));
        playerNamesDisplay[i].setCharacterSize(TEXT_SIZE);
        playerNamesDisplay[i].setFillColor(Color::Black);
        playerNamesDisplay[i].setString(controller -> game -> getPlayerNames()[i]);
        playerNamesDisplay[i].setPosition(
            x * 2.5,
            board.getGlobalBounds().top + TILE_SIZE * i
        );

        playerScoresDisplay.push_back(Text());
        playerScoresDisplay[i].setFont(controller -> resource -> getFont("pixel"));
        playerScoresDisplay[i].setCharacterSize(TEXT_SIZE);
        playerScoresDisplay[i].setFillColor(Color::Black);
        playerScoresDisplay[i].setString(to_string(0));
        playerScoresDisplay[i].setPosition(
            x * 3 + playerNamesDisplay[i].getGlobalBounds().width,
            board.getGlobalBounds().top + TILE_SIZE * i
        );
    }
}
void GameState::drawPlayerDisplay() {
    for (Text t : playerNamesDisplay) {
        controller -> window -> draw(t);
    }
    for (Text t : playerScoresDisplay) {
        controller -> window -> draw(t);
    }
}
void GameState::colorCurrentPlayer() {
    for (size_t i = 0; i < playerNamesDisplay.size(); i++) {
        playerNamesDisplay[i].setFillColor(Color::Black);
    }
    playerNamesDisplay[currentPlayerIndex].setFillColor(Color(172, 50, 50));
}
void GameState::positionRedTile(Vector2i v) {
    redTileSprite.setPosition(
        board.getGlobalBounds().left + v.x * board.getGlobalBounds().width / BUTIN_BOARD_SIZE,
        board.getGlobalBounds().top + v.y * board.getGlobalBounds().height / BUTIN_BOARD_SIZE
    );
}
void GameState::positionBlueTile(sf::Vector2i v) {
    blueTileSprite.setPosition(
        board.getGlobalBounds().left + v.x * board.getGlobalBounds().width / BUTIN_BOARD_SIZE,
        board.getGlobalBounds().top + v.y * board.getGlobalBounds().height / BUTIN_BOARD_SIZE
    );
}
void GameState::drawSelectedTile() {
    if (fromTile != nullptr) {
        positionBlueTile(*fromTile);
        controller -> window -> draw(blueTileSprite);
    }
}
void GameState::drawMovesPossible() {
    for (Vector2i v : movesPossible) {
        positionRedTile(v);
        controller -> window -> draw(redTileSprite);
    }
}
void GameState::gameOver() {
    winner.setString(controller -> game -> getWinner());
    winner.setPosition(controller -> machine -> getCenter().x - winner.getGlobalBounds().width / 2, controller -> machine -> getCenter().y - winner.getGlobalBounds().height / 2);
    printWinner = true;
}

