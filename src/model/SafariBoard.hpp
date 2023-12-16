#ifndef SAFARIBOARD_HPP
#define SAFARIBOARD_HPP

#include <iostream>

#include "Board.hpp"
#include "SafariPiece.hpp"
#include "SafariConfig.hpp"

class SafariBoard : public Board {
private:
    const int tilesToCapture;
    bool isCaptured(const SafariPiece *) const;
    int getAccessibleTiles(const Vector2i &from, const vector<Vector2i> &patterns, vector<vector<bool>> *mark) const;
    vector<Vector2i> getPositionFromPatterns(const Vector2i &from, const vector<Vector2i> &patterns) const;
public:
    SafariBoard();
    virtual ~ SafariBoard();
    SafariBoard(const SafariBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(const Vector2i &from, const Vector2i &to, const int playerIndex);
    virtual const vector<Vector2i> validMoves(const Vector2i &from, const int playerIndex) const;
    bool isWithinBounds(Vector2i pos) const;

    friend ostream &operator<<(ostream &, const SafariBoard &);
};

#endif
