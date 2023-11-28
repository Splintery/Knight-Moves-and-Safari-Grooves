#ifndef BOARD_HPP
#define BOARD_HPP

#include "../utilities/Utilities.hpp"
#include <SFML/System/Vector2.hpp>
using namespace sf;

class Board {
public:
    virtual bool isGameDone() const = 0;
    virtual const vector<vector<vector<string>>> getBoardState() const = 0;
    virtual void makeMove(const Vector2i& from, const Vector2i& to) = 0;
    virtual const vector<Vector2i> validMoves(const Vector2i& from) const = 0;
protected:
    vector<vector<Piece*>> board;
};

#endif
