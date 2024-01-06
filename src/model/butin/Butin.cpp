#include "Butin.hpp"

Butin::Butin() {
    board = new ButinBoard();
    cout << "Construction of " << *this;
}

bool Butin::isGameDone() const{
    if (gameStarted && board -> isGameDone()) {
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

void Butin::initializeGame(const GameConfig &gc) {
    board->initializeGame(gc);
    gameStarted = true;
}

void Butin::makeMove(ActionKey action, const Vector2i &from, const Vector2i &to) {
    ButinPieceType butinPieceType = ((ButinBoard *) board)->getJumpedPieceType(from, to);
    playerList[currentPlayerIndex]->increaseScore(UtilityFunctions::getValueFromColor(butinPieceType));
    board->makeMove(action, currentPlayerIndex, from, to);

    // skip to the next player is no more moves are available
    if (validMoves(action, to).empty()) {
        currentPlayerIndex = (currentPlayerIndex + 1) % playerList.size();
    }
}

vector<string> Butin::getPlayerScores() const {
    vector<string> res;
    for (Player* p : playerList) {
        res.push_back(to_string(p -> getScore()));
    }
    return res;
}

pair<int, int> Butin::getMinMaxPlayers() const {
    return pair<int, int>(2, 2);
}

Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &) {
    o << "Game: Butin" << endl;
    return o;
}

