#ifndef GOUNKI_HPP
#define GOUNKI_HPP

#include "../Game.hpp"
#include "GounkiBoard.hpp"

class Gounki : public Game {
public:
    virtual ~Gounki();
    Gounki();
    Gounki(const Gounki &) = delete;

    virtual bool isGameDone() const;
    virtual string getWinner() const;
    virtual void initializeGame(const GameConfig &);
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to);
    virtual pair<int, int> getMinMaxPlayers() const;

    friend ostream &operator<<(ostream &, const Gounki &);
};

#endif
