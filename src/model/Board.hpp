#ifndef BOARD_HPP
#define BOARD_HPP

#include "../utilities/Utilities.hpp"
#include <SFML/System/Vector2.hpp>
using namespace sf;

template<typename PieceType>
class Board {
public:
    virtual void isValidMove(const Vector2i& from, const Vector2i& to) const = 0;
    virtual const vector<vector<string>> getBoardState() const = 0;
protected:
    vector<vector<PieceType*>> board;
};

#endif
