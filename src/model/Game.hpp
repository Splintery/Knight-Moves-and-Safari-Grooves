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
    bool gameStarted;
    int currentPlayerIndex = 0;
public:
    vector<Player*> playerList;
    Board* board;

    virtual ~Game() = 0;
    virtual bool isGameDone() const = 0;
    virtual string getWinner() const = 0;
    virtual bool hasGameStarted() const = 0;
    virtual void initPlayers(vector<string> playerNames) = 0;
    virtual void initializeGame(const GameConfig&) = 0;
    virtual void makeMove(ActionKey action, const Vector2i& from, const Vector2i& to) = 0;
    virtual const vector<Vector2i> validMoves(ActionKey action, const Vector2i& from) const = 0;
    virtual const vector<vector<vector<string>>> getBoardState() const = 0;
    virtual const int getCurrentPlayerIndex() const = 0;
    virtual vector<string> getPlayerNames() const = 0;
    virtual const pair<int, int> getMinMaxPlayers() const = 0;
    // pair.first = minimum nb of players for game to start
    // pair.second = maximum nb of players for game to start
};

#endif
