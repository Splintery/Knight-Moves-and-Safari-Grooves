#include "ButinBoard.hpp"

ButinBoard::ButinBoard() {
    cout << "Construction of " << *this;
}

bool ButinBoard::initGame() {
    return false;
}

void ButinBoard::isValidMove(pair<pair<int, int>, pair<int, int>> move) {
}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinBoard & bb) {
    o << "Board: Butin" << endl;
    return o;
}

// TODO NOT WORKING
array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> ButinBoard::getBoardState() {
    array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> res;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            res[i][j].push_back(EmptyButin);
        }
    }
    return res;
}

