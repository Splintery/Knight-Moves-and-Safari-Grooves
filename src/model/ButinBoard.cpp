#include "ButinBoard.hpp"

ButinBoard::ButinBoard() {
    cout << "Construction of " << *this;
}

void ButinBoard::initializeGame(vector<Vector2i> deleted_pieces) {
    for (auto &v : deleted_pieces) {

    }
}

void ButinBoard::isValidMove(const Vector2i &from, const Vector2i &to) const {

}

const vector<vector<string>> ButinBoard::getBoardState() const {
    vector<vector<string>> boardState;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            boardState.at(i).push_back(butinSpriteMap.at(board[i][j]->color));
        }
    }
    return boardState;
}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinBoard &) {
    o << "Board: Butin" << endl;
    return o;
}
