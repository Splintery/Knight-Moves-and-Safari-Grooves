#ifndef SAFARIBOARD_HPP
#define SAFARIBOARD_HPP

#include <cmath>
#include <memory>

#include "../Board.hpp"
#include "SafariPiece.hpp"
#include "SafariConfig.hpp"

class SafariBoard : public Board {
private:
    const int nbPlayers;
    const int tilesToCapture;
    bool isCaptured(const SafariPiece *) const;
    int getAccessibleTiles(const Vector2i &from, const vector<Vector2i> &patterns, vector<vector<bool>> *mark) const;
    vector<Vector2i> getPositionFromPatterns(const Vector2i &from, const vector<Vector2i> &patterns) const;
public:
    SafariBoard(int nbPlayers);
    virtual ~ SafariBoard();
    SafariBoard(const SafariBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(ActionKey action, int playerIndex, const Vector2i &from, const Vector2i &to);
    virtual const vector<Vector2i> validMoves(ActionKey action, int playerIndex, const Vector2i &from) const;
    bool isWithinBounds(Vector2i pos) const;

    friend ostream &operator<<(ostream &, const SafariBoard &);
};

#endif
