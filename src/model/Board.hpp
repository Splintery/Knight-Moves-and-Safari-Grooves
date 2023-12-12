#ifndef BOARD_HPP
#define BOARD_HPP

#include "../utilities/Utilities.hpp"
#include "Piece.hpp"
#include <SFML/System/Vector2.hpp>
using namespace sf;

class Board {
public:
    virtual bool isGameDone() const = 0;
    virtual const vector<vector<vector<string>>> getBoardState() const = 0;
    virtual void makeMove(const Vector2i& from, const Vector2i& to, int playerIndex) = 0;
    virtual const vector<Vector2i> validMoves(const Vector2i& from, int playerIndex) const = 0;
    virtual bool isWithinBounds(Vector2i pos) const = 0;
    vector<vector<vector<Piece*>>> board;
protected:
};

#endif
