#ifndef PIECE_HPP
#define PIECE_HPP

#include <utility>
#include <iostream>
#include <vector>
using namespace std;

#include <SFML/System/Vector2.hpp>
using namespace sf;

class Piece {
protected:
    Vector2i position;
public:
    virtual void movePiece(Vector2i position) = 0;
    virtual vector<Vector2i> getMovementPatterns() const = 0;
    virtual const Vector2i& getPosition() const = 0;

    virtual ~Piece() {}
};

#endif