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
public:
    vector<Player*> player_list;
    Board *board;
    virtual void start() = 0;
    virtual void end() = 0;
    virtual bool isGameDone() const = 0;
    virtual void initializeGame(GameConfig *) = 0;
    virtual void makeMove(pair<pair<int, int>, pair<int, int>> move) = 0;
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>> move) = 0;
    virtual string getCurrentPlayer() const = 0;
    
    virtual void setNextMove(Vector2f) = 0;
    virtual bool playNextMove() = 0;
private:
    Vector2f nextMove;
};

#endif
