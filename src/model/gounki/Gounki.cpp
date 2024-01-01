#include "Gounki.hpp"

Gounki::Gounki() {
    gameStarted = false;
    board = new GounkiBoard();
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
    for (Player * p : playerList) {
        if (p->getScore() == GOUNKI_BOARD_SIZE * 2)
            return p->name;
    }
    int index = ((GounkiBoard*)board)->getWinnerIndex();
    return playerList[index]->name;
}

bool Gounki::hasGameStarted() const {
    return gameStarted;
}

void Gounki::initPlayers(vector<string> playerNames) {
    for (const string &s: playerNames) {
        playerList.push_back(new Player(s));
    }
    currentPlayerIndex = 0;
}

void Gounki::initializeGame(const GameConfig &) {
    gameStarted = true;
}

void Gounki::makeMove(ActionKey action, const Vector2i& from, const Vector2i& to) {
    GounkiBoard* gounkiBoard = (GounkiBoard*) board;
    if (action == ActionKey::LeftClick && gounkiBoard->isLandedCaseEnnemy(from, to)) {
        playerList[currentPlayerIndex]->increaseScore(board->board[to.x][to.y].size());
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

const vector<Vector2i> Gounki::validMoves(ActionKey action, const Vector2i &from) const {
    return board->validMoves(action, currentPlayerIndex, from);
}

const vector<vector<vector<string>>> Gounki::getBoardState() const {
    return board->getBoardState();
}

const int Gounki::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

vector<string> Gounki::getPlayerNames() const {
    vector<string> res;
    for (Player* p : playerList) {
        res.push_back(p -> name);
    }
    return res;
}

const pair<int, int> Gounki::getMinMaxPlayers() const {
    return pair<int, int>(2, 2);
}

Gounki::~Gounki() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Gounki &) {
    o << "Game: Gounki" << endl;
    return o;
}

