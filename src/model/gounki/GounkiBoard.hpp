#ifndef GOUNKIBOARD_HPP
#define GOUNKIBOARD_HPP

#include <iostream>
#include <map>
#include <algorithm>

#include "../Board.hpp"
#include "GounkiPiece.hpp"

class GounkiBoard : public Board {
private:
    Vector2i lastDeploymentDirection;
    GounkiPiece* lastDeploymentPiece;
    vector<GounkiPiece*> currentDeployment;
    bool gameDone;
    void generateDefaultBoard();
    const vector<pair<Vector2i, Vector2i>> validMovesPattern(ActionKey action, const Vector2i& from) const;
    void movesWithinDistance(const Vector2i& from, vector<pair<Vector2i, Vector2i>>& movesWithPattern) const;
    void extractMoves(vector<Vector2i>& moves, const vector<pair<Vector2i, Vector2i>>& movesWithPattern) const;
    GounkiPieceType determinePieceType(const Vector2i& from, const Vector2i& to) const;
public:
    GounkiBoard();
    virtual ~GounkiBoard();
    GounkiBoard(const GounkiBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(ActionKey action, int playerIndex, const Vector2i& from, const Vector2i& to);
    virtual const vector<Vector2i> validMoves(ActionKey action, int playerIndex, const Vector2i& from) const;
    bool isWithinBounds(Vector2i pos) const;

    bool isLandedCaseEnnemy(const Vector2i& from, const Vector2i& to) const;
    size_t currentDeploymentSize();

    friend ostream &operator<<(ostream &, const GounkiBoard &);
};

#endif
