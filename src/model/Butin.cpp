#include "Butin.hpp"

Butin::Butin() {
    board = new ButinBoard();
    cout << "Construction of " << *this;
}

void Butin::start() {

}

void Butin::end() {

}

bool Butin::isGameDone() const{
    return false;
}

void Butin::initializeGame(const ButinConfig &bc) {
    for (string s : bc.names){
        player_list.push_back(new Player(s));
    }
    currentPlayer = *player_list.begin();
    board->initializeGame(bc.deleted_pieces);
}

void Butin::makeMove(const Vector2i &from, const Vector2i &to) {

}

const vector<Vector2i> Butin::validMoves(const Vector2i &from) const {
    return vector<Vector2i>();
}

void Butin::isValidMove(const Vector2i &from, const Vector2i &to) const {

}

const string Butin::getCurrentPlayer() const {
    return currentPlayer->name;
}

const vector<vector<string>> Butin::getBoardState() const {
    return board->getBoardState();
}

Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &) {
    o << "Game: Butin" << endl;
    return o;
}

