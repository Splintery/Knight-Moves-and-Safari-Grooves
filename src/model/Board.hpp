#ifndef BOARD_HPP
#define BOARD_HPP

#include "../utilities/Utilities.hpp"
#include <SFML/System/Vector2.hpp>
using namespace sf;

class Board {
public:
    virtual void initializeGame() = 0;
    virtual void isValidMove(Vector2i from, Vector2i to) const = 0;
    virtual vector<vector<string>> getBoardState() const = 0;
};

#endif
