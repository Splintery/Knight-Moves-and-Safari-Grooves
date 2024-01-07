#include "Gounki.hpp"

Gounki::Gounki() {
    board = new GounkiBoard();
    gameStarted = true;
    cout << "Construction of " << *this;
}

bool Gounki::isGameDone() const {
    for (Player * p : playerList) {
        if (p->getScore() == GOUNKI_BOARD_SIZE * 2)
            return true;
    }
    return board->isGameDone();
}

string Gounki::getWinner() const {
    // the winner either ate all the pieces, or landed a piece on a winning position
    for (Player * p : playerList) {
        if (p->getScore() == GOUNKI_BOARD_SIZE * 2)
            return p->name;
    }
    int index = ((GounkiBoard*)board)->getWinnerIndex();
    return playerList[index]->name;
}

void Gounki::initializeGame(const GameConfig &) {
    // no specific initialization for the game Gounki
}

void Gounki::makeMove(ActionKey action, const Vector2i& from, const Vector2i& to) {
    GounkiBoard* gounkiBoard = (GounkiBoard*) board;

    // a classic movement will increase the score of the player if the landed case is an ennemy case
    if (action == ActionKey::LeftClick && gounkiBoard->isLandedCaseEnnemy(from, to)) {
        playerList[currentPlayerIndex]->increaseScore(gounkiBoard->getCaseSize(to));
    }

    board->makeMove(action, currentPlayerIndex, from, to);

    switch (action) {
        // a classic movement is done in one step
        case ActionKey::LeftClick:
            currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
            break;
        case ActionKey::RightClick:
            size_t currentDeploymentSize = gounkiBoard->currentDeploymentSize();
            // it's the next player's turn if the deployment is done
            // or if the deployment can't be finished
            if (currentDeploymentSize == 0
            || board->validMoves(action, currentPlayerIndex, to).size() == 0) {
                currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
                gounkiBoard->clearDeploymentStatus();
            }
            break;
    }
}

pair<int, int> Gounki::getMinMaxPlayers() const {
    return pair<int, int>(2, 2);
}

Gounki::~Gounki() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Gounki &) {
    o << "Game: Gounki" << endl;
    return o;
}