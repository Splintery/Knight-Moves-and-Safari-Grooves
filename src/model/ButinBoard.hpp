#ifndef BUTINBOARD_HPP
#define BUTINBOARD_HPP

#include <vector>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>

#include "ButinPiece.hpp"
#include "Board.hpp"
// #include "../settings/SETTINGS.hpp"
#include "../utilities/Utilities.hpp"

#define BOARD_SIZE 8

class ButinBoard : public Board<ButinPiece> {
private:
    void generateDefaultBoard();
public:
    ButinBoard();
    ButinBoard(const ButinBoard &) = delete;

    virtual void initializeGame(const vector<Vector2i> deleted_pieces);
    virtual void isValidMove(const Vector2i& from, const Vector2i& to) const;
    virtual const vector<vector<string>> getBoardState() const;

    virtual ~ButinBoard();
    friend ostream &operator<<(ostream &, const ButinBoard &);
};

#endif
