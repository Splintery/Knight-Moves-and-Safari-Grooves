#include "ButinPiece.hpp"

ButinPiece::ButinPiece(ButinPieceType color, Vector2i position):value {getValueFromColor(color)}, color {color} {
    this->position = position;
    cout << "Construction of " << *this;
}

vector<Vector2i> ButinPiece::getMovementPatterns() const {
    vector<Vector2i> patterns;

    // diagonal jumps
    patterns.push_back(Vector2i(2, 2));
    patterns.push_back(Vector2i(2, -2));
    patterns.push_back(Vector2i(-2, 2));
    patterns.push_back(Vector2i(-2, -2));
    // straight jumps
    patterns.push_back(Vector2i(0, 2));
    patterns.push_back(Vector2i(0, -2));
    patterns.push_back(Vector2i(2, 0));
    patterns.push_back(Vector2i(-2, 0));
    return patterns;
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
    this->position = position;
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

const Vector2i ButinPiece::getPosition() const {
    return this->position;
}
