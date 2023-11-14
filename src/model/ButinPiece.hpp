#ifndef BUTINPIECE_HPP
#define BUTINPIECE_HPP

#include "Piece.hpp"

enum ButinPieceColor {
    Red,
    Yellow,
    Black
};

class ButinPiece : public Piece {
public:
    ButinPiece(ButinPieceColor color, pair<int, int> position);
    virtual ~ButinPiece();
    ButinPiece(const ButinPiece &) = delete;

    const int value;
    virtual void movePiece(pair<int, int> position);

    friend ostream &operator<<(ostream &, const ButinPiece &);
private:
    int getValueFromColor(ButinPieceColor color) const;
};


#endif
