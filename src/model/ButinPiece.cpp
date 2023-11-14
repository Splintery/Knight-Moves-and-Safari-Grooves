#include "ButinPiece.hpp"

ButinPiece::ButinPiece(ButinPieceColor color, pair<int, int> position):value { getValueFromColor(color) } {
    _position = position;
    cout << "Construction of " << this;
}

int ButinPiece::getValueFromColor(ButinPieceColor color) const{
    switch (color) {
        case Black:
            return 3;
        case Red:
            return 2;
        case Yellow:
            return 1;
    }
    return 0;
}

ButinPiece::~ButinPiece() {
    cout << "Destruction of " << this;
}

ostream &operator<<(ostream &o, const ButinPiece &bp) {
    o << "Piece: Butin" << endl << "\t Value: " << bp.value << endl;
    return o;
}

void ButinPiece::movePiece(pair<int, int> position) {
    _position = position;
}
