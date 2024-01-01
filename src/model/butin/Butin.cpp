#include "Butin.hpp"

Butin::Butin() {
    gameStarted = false;
    board = new ButinBoard();
//    cout << "Construction of " << *this;
}

bool Butin::hasGameStarted() const {
    return gameStarted;
}

bool Butin::isGameDone() const{
    if (board -> isGameDone()) {
        int totalPointsRemaining = ((ButinBoard *) board) -> getBoardTotalPoints();
        playerList[(currentPlayerIndex - 1) % playerList.size()] -> increaseScore(-totalPointsRemaining);
        return true;
    }
    return false;
}

string Butin::getWinner() const {
    int max = 0;
    Player* winner = nullptr;
    for (Player* player : playerList) {
        if (player->getScore() > max) {
            max = player->getScore();
            winner = player;
        }
    }
    return winner->name;
}

void Butin::initPlayers(vector<std::string> playerNames) {
    for (const string& s : playerNames){
        playerList.push_back(new Player(s));
    }
    currentPlayerIndex = 0;
}

void Butin::initializeGame(const GameConfig &gc) {
    board->initializeGame(gc);
    gameStarted = true;
}

void Butin::makeMove(ActionKey action, const Vector2i &from, const Vector2i &to) {
    playerList[currentPlayerIndex]->increaseScore(((ButinBoard *) board)->getJumpedPieceType(from, to));
    board->makeMove(action, currentPlayerIndex, from, to);

    // skip to the next player is no more moves are available
    if (validMoves(action, to).empty()) {
        currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
    }
}

const vector<Vector2i> Butin::validMoves(ActionKey action, const Vector2i &from) const {
    return board->validMoves(action, currentPlayerIndex, from);
}

const vector<vector<vector<string>>> Butin::getBoardState() const {
    return board->getBoardState();
}

vector<string> Butin::getPlayerScores() const {
    vector<string> res;
    for (Player* p : playerList) {
        res.push_back(to_string(p -> getScore()));
    }
    return res;
}

const int Butin::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}

vector<string> Butin::getPlayerNames() const {
    vector<string> res;
    for (Player* p : playerList) {
        res.push_back(p -> name);
    }
    return res;
}

const pair<int, int> Butin::getMinMaxPlayers() const {
    const pair<int, int> res(2, 2);
    return res;
}

Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &) {
    o << "Game: Butin" << endl;
    return o;
}

