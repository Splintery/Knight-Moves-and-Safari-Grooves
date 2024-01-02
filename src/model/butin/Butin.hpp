#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "../Game.hpp"
#include "ButinBoard.hpp"
#include "ButinConfig.hpp"

class Butin : public Game {
private:
public:
    Butin();
    virtual ~Butin();
    Butin(const Butin &) = delete;

    virtual bool isGameDone() const;
    virtual string getWinner() const;
    virtual bool hasGameStarted() const;
    virtual void initPlayers(vector<string> playerNames);
    virtual void initializeGame(const GameConfig &);
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to);
    virtual const vector<Vector2i> validMoves(ActionKey action, const Vector2i& from) const;
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual const int getCurrentPlayerIndex() const;
    virtual vector<string> getPlayerNames() const;
    virtual const pair<int, int> getMinMaxPlayers() const;

    vector<string> getPlayerScores() const;

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
