#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>
using namespace std;

#include "Board.hpp"

#define BOARD_SIZE 8

class ButinBoard : public Board {
public:
    ButinBoard();
    ButinBoard(const ButinBoard &) = delete;

    virtual bool initGame();
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>> move);
    array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> getBoardState();

    virtual ~ButinBoard();
    friend ostream &operator<<(ostream &, const ButinBoard &);
protected:
    array<array<Tile, BOARD_SIZE>, BOARD_SIZE> board;
};

#endif
