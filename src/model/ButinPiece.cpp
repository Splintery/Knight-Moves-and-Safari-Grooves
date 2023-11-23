#include "ButinPiece.hpp"

ButinPiece::ButinPiece(ButinPieceType color, Vector2i position): color {color}, value {getValueFromColor(color)} {
    position = position;
    cout << "Construction of " << *this;
}

int ButinPiece::getValueFromColor(ButinPieceType type) const{
    switch (type) {
        case ButinPieceType::Black:
            return 3;
        case ButinPieceType::Red:
            return 2;
        case ButinPieceType::Yellow:
            return 1;
        case ButinPieceType::EmptyButin:
            return -1;
    }
    return 0;
}

void ButinPiece::movePiece(Vector2i position) {

}

// TODO SUPPRIMER
ButinPiece::ButinPiece(): color{ButinPieceType::Red}, value{1} {

}

ButinPiece::~ButinPiece() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinPiece &bp) {
    o << "Piece: Butin" << endl << "\t Value: " << bp.value << endl;
    return o;
}