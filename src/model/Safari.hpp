#ifndef SAFARI_HPP
#define SAFARI_HPP

#include "Game.hpp"
#include "SafariConfig.hpp"

class Safari : public Game {
private:
    virtual ~Safari();
public:
    Safari();
    Safari(const Safari &) = delete;

    virtual bool isGameDone() const;
    virtual string getWinner() const;
    virtual bool hasGameStarted() const;
    virtual void initPlayers(vector<string> playerNames);
    virtual void initializeGame(const GameConfig &);
    virtual void makeMove(const Vector2i& from, const Vector2i& to);
    virtual const vector<Vector2i> validMoves(const Vector2i& from) const;
    virtual const vector<vector<vector<string>>> getBoardState() const;
    virtual vector<string> getPlayerScores() const;
    virtual const int getCurrentPlayerIndex() const;
    virtual vector<string> getPlayerNames() const;
    virtual const pair<int, int> getMinMaxPlayers() const;

    friend ostream &operator<<(ostream &, const Safari &);
};

#endif
