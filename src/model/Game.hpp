#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <array>
#include <iostream>
using namespace std;

#include "Player.hpp"
#include "Board.hpp"
#include "GameConfig.hpp"

class Game {
protected:
    Board* board;
    vector<Player*> playerList;
    bool gameStarted = false;
    int currentPlayerIndex = 0;
public:
    virtual ~Game() {};

    // Pure virtual functions
    virtual bool isGameDone() const = 0;
    virtual string getWinner() const = 0;
    virtual void initializeGame(const GameConfig&) = 0;
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to) = 0;
    virtual pair<int, int> getMinMaxPlayers() const = 0;

    // Virtual functions
    virtual bool hasGameStarted() const;
    virtual void initPlayers(vector<string> playerNames);
    virtual vector<Vector2i> validMoves(ActionKey action, const Vector2i& from) const;
    virtual vector<vector<vector<string>>> getBoardState() const;
    virtual int getCurrentPlayerIndex() const;
    virtual vector<string> getPlayerNames() const;
    // pair.first = minimum nb of players for game to start
    // pair.second = maximum nb of players for game to start
};

#endif
