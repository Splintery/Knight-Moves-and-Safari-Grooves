#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

#include "ButinPiece.hpp"
#include "Board.hpp"
#include "ButinConfig.hpp"
#include "../settings/SETTINGS.hpp"

class ButinBoard : public Board {
private:
    void generateDefaultBoard();
    const Vector2i calculateJumpedPos(const Vector2i &from, const Vector2i &to) const;

public:
    ButinBoard();
    ButinBoard(const ButinBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(const Vector2i& from, const Vector2i& to, const int playerIndex);
    virtual const vector<Vector2i> validMoves(const Vector2i& from, const int playerIndex) const;
    virtual bool isWithinBounds(Vector2i pos) const;
    ButinPieceType getJumpedPieceType(const Vector2i &from, const Vector2i &to) const;
    int getBoardTotalPoints() const;

    virtual ~ButinBoard();
    friend ostream &operator<<(ostream &, const ButinBoard &);
};

#endif
