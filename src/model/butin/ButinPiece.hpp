#ifndef BUTINPIECE_HPP
#define BUTINPIECE_HPP

#include "../Piece.hpp"
#include "../../utilities/Utilities.hpp"

class ButinPiece : public Piece {
public:
    ButinPiece(ButinPieceType color, Vector2i position);
    virtual ~ButinPiece();
    ButinPiece(const ButinPiece &) = delete;
    ButinPiece& operator=(const ButinPiece&) = delete;

    const int value;
    const ButinPieceType color;

    virtual void movePiece(Vector2i position);
    virtual vector<Vector2i> getMovementPatterns() const;
    virtual const Vector2i& getPosition() const;

    friend ostream &operator<<(ostream &, const ButinPiece &);
};

#endif
