#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "Game.hpp"
#include "ButinBoard.hpp"
#include "ButinConfig.hpp"

class Butin : public Game {
private:
    virtual ~Butin();
public:
    Butin();
    Butin(const Butin &) = delete;
    // TODO JSP SI CEST CEST BIEN DE FAIRE CA OU S'IL VAUT MIEUX CAST DANS CHAQUE FONCTION
    ButinBoard *board;

    virtual void start();
    virtual void end();
    virtual bool isGameDone() const;
    virtual void initializeGame(GameConfig *);
    virtual void makeMove(pair<pair<int, int>, pair<int, int>> move);
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>> move);
    virtual string getCurrentPlayer() const;
    array<array<vector<ButinPieceType>, BOARD_SIZE>, BOARD_SIZE> getBoardState();

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
