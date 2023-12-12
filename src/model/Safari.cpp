#include "Safari.hpp"

Safari::Safari() {
    // board = new SafariBoard();
    cout << "Construction of " << *this;
}

bool Safari::isGameDone() const {
    return board->isGameDone();
}

string Safari::getWinner() const {
    return std::string();
}

bool Safari::hasGameStarted() const {
    return false;
}

void Safari::initPlayers(vector<string> playerNames) {

}

void Safari::initializeGame(const GameConfig &) {

}

void Safari::makeMove(const Vector2i &from, const Vector2i &to) {

}

const vector<Vector2i> Safari::validMoves(const Vector2i &from) const {
    return vector<Vector2i>();
}

const vector<vector<vector<string>>> Safari::getBoardState() const {
    return vector<vector<vector<string>>>();
}

vector<string> Safari::getPlayerScores() const {
    return vector<string>();
}

const int Safari::getCurrentPlayerIndex() const {
    return 0;
}

vector<string> Safari::getPlayerNames() const {
    return vector<string>();
}

const pair<int, int> Safari::getMinMaxPlayers() const {
    return pair<int, int>();
}

Safari::~Safari() {

}

ostream &operator<<(ostream &o, const Safari &s) {
    return o;
}

