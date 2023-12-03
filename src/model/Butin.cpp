#include "Butin.hpp"

Butin::Butin() {
    gameStarted = false;
    board = new ButinBoard();
    cout << "Construction of " << *this;
}
bool Butin::hasGameStarted() const {
    return gameStarted;
}
bool Butin::isGameDone() const{
    return board->isGameDone();
}
void Butin::initPlayers(vector<std::string> playerNames) {
    for (const string& s : playerNames){
        player_list.push_back(new Player(s));
    }
    currentPlayer = *player_list.begin();
}
void Butin::initializeGame(const GameConfig &gc) {
    ButinConfig &bc = (ButinConfig &) gc;
    ((ButinBoard *) board)->initializeGame(bc.deleted_pieces);
    gameStarted = true;
}

void Butin::makeMove(const Vector2i &from, const Vector2i &to) {
    currentPlayer->increaseScore(((ButinBoard *) board)->getJumpedPieceType(from, to));
    board->makeMove(from, to);
}

const vector<Vector2i> Butin::validMoves(const Vector2i &from) const {
    return board->validMoves(from);
}

const string Butin::getCurrentPlayer() const {
    return currentPlayer->name;
}

const vector<vector<vector<string>>> Butin::getBoardState() const {
    return board->getBoardState();
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

