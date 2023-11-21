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
    Player* currentPlayer;
    virtual void isValidMove(Vector2i from, Vector2i to) const = 0;
public:
    vector<Player*> player_list;
    Board *board;
    virtual void start() = 0;
    virtual void end() = 0;
    virtual bool isGameDone() const = 0;
    virtual void initializeGame(GameConfig *) = 0;
    virtual void makeMove(Vector2i from, Vector2i to) = 0;
    virtual vector<Vector2i> validMoves(Vector2i from) const = 0;
    virtual string getCurrentPlayer() const = 0;
    virtual vector<vector<string>> getBoardState() const = 0;
};

#endif
