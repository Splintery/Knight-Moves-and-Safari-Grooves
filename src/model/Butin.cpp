#include "Butin.hpp"

Butin::Butin(vector<string> names) {
    board = new ButinBoard();
    for (string s : names){
        player_list.push_back(new Player(s));
    }
    cout << "Construction of " << this;
}

void Butin::start() {

}

void Butin::end() {

}

bool Butin::isGameDone() {
    return false;
}

void Butin::initGame() {

}

void Butin::isValidMove(pair<pair<int, int>, pair<int, int>>) {
    
}

void Butin::makeMove(pair<pair<int, int>, pair<int, int>>) {

}

Butin::~Butin() {
    cout << "Destruction of " << this;
}

ostream &operator<<(ostream &o, const Butin &b) {
    o << "Game: Butin" << endl;
    return o;
}

