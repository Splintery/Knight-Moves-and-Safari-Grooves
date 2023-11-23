#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>

#include "ButinPiece.hpp"
#include "Board.hpp"
#include "../utilities/Utilities.hpp"

#define BOARD_SIZE 8

class ButinBoard : public Board<ButinPiece> {
private:
    void generateDefaultBoard();
    bool isWithinBounds(Vector2i pos) const;
public:
    ButinBoard();
    ButinBoard(const ButinBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const vector<Vector2i> deleted_pieces);
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(const Vector2i& from, const Vector2i& to);
    virtual const vector<Vector2i> validMoves(const Vector2i& from) const;

    virtual ~ButinBoard();
    friend ostream &operator<<(ostream &, const ButinBoard &);
};

#endif
