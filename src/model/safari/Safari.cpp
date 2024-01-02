#include "Safari.hpp"


Safari::Safari() {
    this -> board = new SafariBoard();
    cout << "Construction of " << *this;
}

void Safari::updateScores() {
    for (size_t i = 0; i < playerList.size(); i++) {
        playerList[i]->setScore(ANIMALS_PER_PLAYER - ((SafariBoard *)board) -> getCapturedPieces(i));
    }
}

bool Safari::isGameDone() const {
    if (gameStarted) {
        switch (playerList.size()) {
            case 2:
                return playerList[0]->getScore() == 0 || playerList[1]->getScore() == 0;
            case 3:
                return (playerList[0]->getScore() == 0 && playerList[1]->getScore() == 0)
                       || (playerList[1]->getScore() == 0 && playerList[2]->getScore() == 0)
                       || (playerList[2]->getScore() == 0 && playerList[0]->getScore() == 0);
        }
    }
    return false;
}

string Safari::getWinner() const {
    int max = playerList[0] -> getScore();
    int index = 0;
    for (size_t i = 0; i < playerList.size(); i++) {
        if (max < playerList[i] -> getScore()) {
            max = playerList[i] -> getScore();
            index = i;
        }
    }
    return playerList[index] -> name;
}

bool Safari::hasGameStarted() const {
    return gameStarted;
}

void Safari::initPlayers(vector<string> playerNames) {
    for (size_t i = 0; i < playerNames.size(); i++){
        playerList.push_back(new Player(playerNames[i]));
        playerList[i] -> increaseScore(3);
    }
    currentPlayerIndex = 0;
}

void Safari::initializeGame(const GameConfig &gc) {
    board->initializeGame(gc);
    updateScores();
    gameStarted = true;
    currentStep = 0;
}

void Safari::makeMove(ActionKey action, const Vector2i &from, const Vector2i &to) {
    board->makeMove(action, currentPlayerIndex, from, to);
    currentStep++;
    updateScores();
    if (currentStep == 2) {
        currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
        currentStep = 0;
        if (playerList[currentPlayerIndex] -> getScore() == 0) {
            currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
        }
    }
}

const vector<Vector2i> Safari::validMoves(ActionKey action, const Vector2i &from) const {
    return board->validMoves(action, currentPlayerIndex, from);
}

const vector<vector<vector<string>>> Safari::getBoardState() const {
    return board->getBoardState();
}

const int Safari::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

vector<string> Safari::getPlayerNames() const {
    vector<string> res;
    for (Player* p : playerList) {
        res.push_back(p -> name);
    }
    return res;
}

const pair<int, int> Safari::getMinMaxPlayers() const {
    const pair<int, int> res(2, 3);
    return res;
}

Safari::~Safari() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Safari &) {
    o << "Game: Safari" << endl;
    return o;
}

