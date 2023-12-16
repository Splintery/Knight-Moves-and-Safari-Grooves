#ifndef BUTINPIECE_HPP
#define BUTINPIECE_HPP

#include "../Piece.hpp"
#include "../../utilities/Utilities.hpp"

class ButinPiece : public Piece {
public:
    ButinPiece(ButinPieceType color, Vector2i position);
    virtual ~ButinPiece();
    ButinPiece(const ButinPiece &) = delete;

    const int value;
    const ButinPieceType color;

    virtual const Vector2i getPosition() const;
    virtual vector<Vector2i> getMovementPatterns() const;
    virtual void movePiece(Vector2i position);

    friend ostream &operator<<(ostream &, const ButinPiece &);
};


#endif
