#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "../Game.hpp"
#include "ButinBoard.hpp"
#include "ButinConfig.hpp"

class Butin : public Game {
public:
    Butin();
    virtual ~Butin();
    Butin(const Butin &) = delete;

    virtual bool isGameDone() const;
    virtual string getWinner() const;
    virtual void initializeGame(const GameConfig &);
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to);
    virtual pair<int, int> getMinMaxPlayers() const;

    vector<string> getPlayerScores() const;

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
