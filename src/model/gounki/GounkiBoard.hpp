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
    vector<pair<Vector2i, Vector2i>> validMovesPattern(ActionKey action, const Vector2i& from) const;
    GounkiPieceType determinePieceType(const Vector2i& from, const Vector2i& to) const;
    Vector2i handleRebounds(vector<Vector2i>::const_iterator it, Vector2i finalPos) const;
    map<GounkiPieceType, int> calculatePieceDistribution(ActionKey action, const Vector2i &from) const;
    bool isWinningPosition(const Vector2i& position) const;
    bool isNextCaseTakeable(ActionKey action, const Vector2i &from, const Vector2i &to) const;
public:
    GounkiBoard();
    GounkiBoard(const GounkiBoard &) = delete;

    virtual bool isGameDone() const;
    virtual void initializeGame(const GameConfig&);
    virtual vector<vector<vector<string>>> getBoardState() const;
    virtual void makeMove(ActionKey action, int playerIndex, const Vector2i& from, const Vector2i& to);
    virtual vector<Vector2i> validMoves(ActionKey action, int playerIndex, const Vector2i& from) const;
    bool isWithinBounds(Vector2i pos) const;

    bool isLandedCaseEnnemy(const Vector2i& from, const Vector2i& to) const;
    size_t currentDeploymentSize() const;
    int getWinnerIndex() const;
    int getCaseSize(const Vector2i& pos) const;
    void clearDeploymentStatus();

    virtual ~GounkiBoard();
    friend ostream &operator<<(ostream &, const GounkiBoard &);
};

#endif
