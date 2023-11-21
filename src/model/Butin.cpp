#include "Butin.hpp"

Butin::Butin() {
    board = new ButinBoard();

    cout << "Construction of " << *this;
    currentPlayer = *player_list.begin();
}

void Butin::start() {

}

void Butin::end() {

}

bool Butin::isGameDone() const{
    return false;
}

void Butin::initializeGame(GameConfig *g) {
    ButinConfig *c = (ButinConfig *) g;
    for (string s : g->names){
        player_list.push_back(new Player(s));
    }
}

vector<Vector2i> Butin::validMoves(Vector2i from) const {
    return vector<Vector2i>();
}

void Butin::makeMove(Vector2i from, Vector2i to) {

}

vector<vector<string>> Butin::getBoardState() const {
    return vector<vector<string>>();
}

void Butin::isValidMove(Vector2i from, Vector2i to) const {

}

string Butin::getCurrentPlayer() const {
    return currentPlayer->name;
}

Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &b) {
    o << "Game: Butin" << endl;
    return o;
}