#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

#include "ButinPiece.hpp"
#include "../Board.hpp"
#include "ButinConfig.hpp"
#include "../../settings/SETTINGS.hpp"

class ButinBoard : public Board {
private:
    void generateDefaultBoard();
    Vector2i calculateJumpedPos(const Vector2i &from, const Vector2i &to) const;
public:
    ButinBoard();
    virtual ~ButinBoard();
    ButinBoard(const ButinBoard &) = delete;
    ButinBoard& operator=(const ButinBoard&) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(ActionKey action, int playerIndex, const Vector2i& from, const Vector2i& to);
    virtual vector<Vector2i> validMoves(ActionKey action, int playerIndex, const Vector2i& from) const;
    virtual bool isWithinBounds(Vector2i pos) const;

    ButinPieceType getJumpedPieceType(const Vector2i &from, const Vector2i &to) const;
    int getBoardTotalPoints() const;

    friend ostream &operator<<(ostream &, const ButinBoard &);
};

#endif
