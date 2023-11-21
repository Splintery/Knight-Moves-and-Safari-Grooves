#include "ButinPiece.hpp"

ButinPiece::ButinPiece(ButinPieceType color, Vector2i position):value {getValueFromColor(color)}, color {color} {
    position = position;
    cout << "Construction of " << *this;
}

int ButinPiece::getValueFromColor(ButinPieceType type) const{
    switch (type) {
        case Black:
            return 3;
        case Red:
            return 2;
        case Yellow:
            return 1;
        case EmptyButin:
            return -1;
    }
    return 0;
}

void ButinPiece::movePiece(Vector2i position) {

}

// TODO SUPPRIMER
ButinPiece::ButinPiece(): color{Red}, value{1} {

}

ButinPiece::~ButinPiece() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinPiece &bp) {
    o << "Piece: Butin" << endl << "\t Value: " << bp.value << endl;
    return o;
}