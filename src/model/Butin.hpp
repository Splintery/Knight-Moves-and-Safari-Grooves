#ifndef BUTIN_HPP
#define BUTIN_HPP

#include "Game.hpp"
#include "ButinBoard.hpp"
#include "ButinConfig.hpp"

class Butin : public Game<ButinBoard, ButinConfig> {
private:
    virtual ~Butin();
    virtual void isValidMove(const Vector2i& from, const Vector2i& to) const;
public:
    Butin();
    Butin(const Butin &) = delete;

    virtual void start();
    virtual void end();
    virtual bool isGameDone() const;
    virtual void initializeGame(const ButinConfig &);
    virtual void makeMove(const Vector2i& from, const Vector2i& to);
    virtual const vector<Vector2i> validMoves(const Vector2i& from) const;
    virtual const vector<vector<string>> getBoardState() const;
    virtual const string getCurrentPlayer() const;

    friend ostream &operator<<(ostream &, const Butin &);
};

#endif
