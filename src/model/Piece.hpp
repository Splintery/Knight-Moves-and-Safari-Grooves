#ifndef PIECE_HPP
#define PIECE_HPP

#include <utility>
#include <iostream>
using namespace std;

class Piece {
protected:
    pair<int, int> position;
public:
    virtual void movePiece(pair<int, int> position) = 0;
};

#endif