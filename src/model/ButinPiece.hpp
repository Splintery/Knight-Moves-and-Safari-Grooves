#ifndef BUTINPIECE_HPP
#define BUTINPIECE_HPP

#include "Piece.hpp"
#include "../utilities/Utilities.hpp"

class ButinPiece : public Piece {
public:
    ButinPiece(ButinPieceType color, pair<int, int> position);
    virtual ~ButinPiece();
    ButinPiece(const ButinPiece &) = delete;

    virtual void movePiece(pair<int, int> position);
    const int value;
    const ButinPieceType color;

    friend ostream &operator<<(ostream &, const ButinPiece &);
private:
    int getValueFromColor(ButinPieceType color) const;
};


#endif
