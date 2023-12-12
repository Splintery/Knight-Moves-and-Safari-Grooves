#ifndef SAFARIPIECE_HPP
#define SAFARIPIECE_HPP

#include "Piece.hpp"
#include "../utilities/Utilities.hpp"

class SafariPiece : public Piece {
    public:
        SafariPiece(SafariPieceType animal, Vector2i position);
        virtual ~ SafariPiece();
        SafariPiece(const SafariPiece &) = delete;

        const SafariPieceType animal;

        virtual void movePiece(Vector2i position);
        virtual vector<Vector2i> getMovementPatterns() const;
        virtual const Vector2i getPosition() const;

    friend ostream &operator<<(ostream &, const SafariPiece &);

};

#endif
