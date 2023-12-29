#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <SFML/System/Vector2.hpp>
using namespace sf;

#include "../utilities/Utilities.hpp"
#include "Piece.hpp"
#include "GameConfig.hpp"
#include "../settings/SETTINGS.hpp"

class Board {
public:
    virtual bool isGameDone() const = 0;
    virtual void initializeGame(const GameConfig&) = 0;
    virtual const vector<vector<vector<string>>> getBoardState() const = 0;
    virtual void makeMove(ActionKey action, int playerIndex, const Vector2i& from, const Vector2i& to) = 0;
    virtual const vector<Vector2i> validMoves(ActionKey action, int playerIndex, const Vector2i& from) const = 0;
    virtual bool isWithinBounds(Vector2i pos) const = 0;
    vector<vector<vector<Piece*>>> board;
protected:
};

#endif
