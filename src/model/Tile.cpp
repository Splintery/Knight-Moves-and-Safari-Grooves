#include "Tile.hpp"

Tile::Tile() {
    cout << "Construction of " << this;
}

Tile::~Tile() {
    cout << "Destruction of " << this;
}

ostream &operator<<(ostream &o, const Tile &t) {
    o << "Tile: ";
    for (Piece *p : t.pieces) {
        o << "\t" << p << endl;
    }
    return o;
}

void Tile::movePieces(pair<int, int> position) {
    for (Piece *p : pieces) {
        p->movePiece(position);
    }
}
