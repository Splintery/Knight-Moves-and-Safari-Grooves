#ifndef SAFARIBOARD_HPP
#define SAFARIBOARD_HPP

#include <iostream>

#include "Board.hpp"
#include "SafariPiece.hpp"


class SafariBoard : public Board {
    public:
        SafariBoard();
        virtual ~ SafariBoard();
        SafariBoard(const SafariBoard &) = delete;

        virtual bool isGameDone() const;
        virtual const vector<vector<vector<string>>> getBoardState() const;
        virtual void makeMove(const Vector2i &from, const Vector2i &to, const int playerIndex);
        virtual const vector<Vector2i> validMoves(const Vector2i &from, const int playerIndex) const;
        bool isWithinBounds(Vector2i pos) const;

        // Un vecteur de pos par joueur sera transféré
        // d'abord les Crocodile, puis les Elephants et enfin les Lions
        virtual void initializeGame(const vector<Vector2i> crocodiles, const vector<Vector2i> elephants, const vector<Vector2i> lions, vector<Vector2i> fences);

    friend ostream &operator<<(ostream &, const SafariBoard &);
};

#endif
