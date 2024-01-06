#ifndef SAFARI_HPP
#define SAFARI_HPP

#include "../Game.hpp"
#include "SafariConfig.hpp"
#include "SafariBoard.hpp"

class Safari : public Game {
private:
    int currentStep;
    void updateScores();
public:
    Safari();
    virtual ~Safari();
    Safari(const Safari &) = delete;

    virtual bool isGameDone() const;
    virtual string getWinner() const;
    void initPlayers(vector<string> playerNames) override;
    virtual void initializeGame(const GameConfig &);
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to = Vector2i(0, 0));
    virtual pair<int, int> getMinMaxPlayers() const;

    friend ostream &operator<<(ostream &, const Safari &);
};

#endif
