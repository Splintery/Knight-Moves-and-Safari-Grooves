#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include <array>
#include <iostream>
using namespace std;

#include "Piece.hpp"

class Tile {
public:
    Tile();
    virtual ~Tile();
    Tile(const Tile &) = delete;

    void movePieces(pair<int, int> position);

    friend ostream &operator<<(ostream &, const Tile &);
protected:
    vector<Piece *> pieces;
};

#endif