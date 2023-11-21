#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "Game.hpp"
#include "ButinBoard.hpp"
#include "ButinConfig.hpp"

class Butin : public Game {
private:
    virtual ~Butin();
    virtual void isValidMove(Vector2i from, Vector2i to) const;
public:
    Butin();
    Butin(const Butin &) = delete;

    virtual void start();
    virtual void end();
    virtual bool isGameDone() const;
    virtual void initializeGame(GameConfig *);
    virtual string getCurrentPlayer() const;
    virtual void makeMove(Vector2i from, Vector2i to);
    virtual vector<Vector2i> validMoves(Vector2i from) const;
    virtual vector<vector<string>> getBoardState() const;

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
