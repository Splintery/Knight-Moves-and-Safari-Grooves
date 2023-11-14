#include "ButinBoard.hpp"

ButinBoard::ButinBoard() {
    cout << "Construction of " << this;
}

bool ButinBoard::initGame() {
    return false;
}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << this;
}

ostream &operator<<(ostream &o, const ButinBoard & bb) {
    o << "Board: Butin" << endl;
    return o;
}
