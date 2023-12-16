#include "Safari.hpp"

Safari::Safari() {
    board = new SafariBoard();
    cout << "Construction of " << *this;
}

bool Safari::isGameDone() const {
    return board->isGameDone();
}

// TODO getWinner
string Safari::getWinner() const {
    return std::string();
}

bool Safari::hasGameStarted() const {
    return gameStarted;
}

void Safari::initPlayers(vector<string> playerNames) {
    for (const string& s : playerNames){
        playerList.push_back(new Player(s));
    }
    currentPlayerIndex = 0;
}

void Safari::initializeGame(const GameConfig &gc) {
    board->initializeGame(gc);
    gameStarted = true;
    currentStep = 0;
}

void Safari::makeMove(ActionKey action, const Vector2i &from, const Vector2i &to) {
    board->makeMove(action, from, to, currentPlayerIndex);
    currentStep++;
    if (currentStep == 2) {
        currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
        currentStep = 0;
    }
}

const vector<Vector2i> Safari::validMoves(const Vector2i &from) const {
    return board->validMoves(from, currentPlayerIndex);
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
