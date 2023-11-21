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

void Butin::isValidMove(pair<pair<int, int>, pair<int, int>> move) {

}

void Butin::makeMove(pair<pair<int, int>, pair<int, int>> move) {

}

string Butin::getCurrentPlayer() const {
    return currentPlayer->name;
}

array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> Butin::getBoardState() {
    return board->getBoardState();
}


Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &b) {
    o << "Game: Butin" << endl;
    return o;
}