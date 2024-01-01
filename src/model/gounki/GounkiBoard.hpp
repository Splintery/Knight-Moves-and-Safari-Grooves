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
    int winningPlayer;

    void generateDefaultBoard();
    const vector<pair<Vector2i, Vector2i>> validMovesPattern(ActionKey action, const Vector2i& from) const;
    GounkiPieceType determinePieceType(const Vector2i& from, const Vector2i& to) const;
    Vector2i handleRebounds(vector<Vector2i>::const_iterator it, Vector2i finalPos) const;
    map<GounkiPieceType, int> calculatePieceDistribution(ActionKey action, const Vector2i &from) const;
    bool isWinningPosition(const Vector2i& position) const;
    bool isNextCaseTakeable(ActionKey action, const Vector2i &from, const Vector2i &to) const;
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
    size_t currentDeploymentSize() const;
    void clearDeploymentStatus();
    int getWinnerIndex() const;

    friend ostream &operator<<(ostream &, const GounkiBoard &);
};

#endif
