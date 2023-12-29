#ifndef GOUNKIPIECE_HPP
#define GOUNKIPIECE_HPP

#include <map>

#include "../Piece.hpp"
#include "../../utilities/Utilities.hpp"

class GounkiPiece : public Piece {
private:
public:
    GounkiPiece(GounkiPieceType type, Vector2i position);
    virtual ~GounkiPiece();
    GounkiPiece(const GounkiPiece &) = delete;

    const GounkiPieceType type;
    static const map<GounkiPieceType, vector<Vector2i>> gounkiMovements;

    virtual void movePiece(Vector2i position);
    virtual vector<Vector2i> getMovementPatterns() const;
    virtual const Vector2i getPosition() const;

    friend ostream &operator<<(ostream &, const GounkiPiece &);
};

#endif
