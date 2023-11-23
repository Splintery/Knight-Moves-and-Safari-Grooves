#ifndef PIECE_HPP
#define PIECE_HPP

#include <utility>
#include <iostream>
using namespace std;
#include <SFML/System/Vector2.hpp>
using namespace sf;

class Piece {
protected:
    Vector2i position;
public:
    virtual void movePiece(Vector2i position) = 0;
};

#endif