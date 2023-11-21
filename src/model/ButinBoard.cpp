#include "ButinBoard.hpp"

ButinBoard::ButinBoard() {
    cout << "Construction of " << *this;
}

void ButinBoard::initializeGame() {

}

void ButinBoard::isValidMove(Vector2i from, Vector2i to) const {

}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinBoard &) {
    o << "Board: Butin" << endl;
    return o;
}

vector<vector<string>> ButinBoard::getBoardState() const {
    vector<vector<string>> boardState;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            boardState.at(i).push_back(butinSpriteMap.at(board[i][j].color));
        }
    }
    return boardState;
}

/*
array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> ButinBoard::getBoardState() {
    array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> res;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            res[i][j].push_back(EmptyButin);
        }
    }
    return res;
}
*/
