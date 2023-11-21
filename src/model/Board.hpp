#ifndef BOARD_HPP
#define BOARD_HPP

#include "Tile.hpp"
#include "../utilities/Utilities.hpp"

class Board {
public:
    virtual bool initGame() = 0;
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>> move) = 0;
};

#endif
