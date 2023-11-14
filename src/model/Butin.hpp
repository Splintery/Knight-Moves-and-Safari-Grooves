#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "Game.hpp"
#include "ButinBoard.hpp"

class Butin : public Game {
private:
    virtual ~Butin();
public:
    Butin(vector<string> names);
    Butin(const Butin &) = delete;

    virtual void start();
    virtual void end();
    virtual bool isGameDone();
    virtual void initGame();
    virtual void makeMove(pair<pair<int, int>, pair<int, int>>);
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>>);

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
