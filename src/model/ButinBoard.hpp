#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>

#include "ButinPiece.hpp"
#include "Board.hpp"
#include "../utilities/Utilities.hpp"

#define BOARD_SIZE 8

class ButinBoard : public Board {
public:
    ButinBoard();
    ButinBoard(const ButinBoard &) = delete;

    virtual void initializeGame();
    virtual void isValidMove(Vector2i from, Vector2i to) const;
    virtual vector<vector<string>> getBoardState() const;

    virtual ~ButinBoard();
    friend ostream &operator<<(ostream &, const ButinBoard &);
private:
    array<array<ButinPiece, BOARD_SIZE>, BOARD_SIZE> board;
};

#endif
