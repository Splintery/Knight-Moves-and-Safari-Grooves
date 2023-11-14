#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <array>
#include <iostream>
using namespace std;

#include "Player.hpp"
#include "Board.hpp"

class Game {
public:
    vector<Player*> player_list;
    Board *board;
    virtual void start() = 0;
    virtual void end() = 0;
    virtual bool isGameDone() = 0;
    virtual void initGame() = 0;
    virtual void makeMove(pair<pair<int, int>, pair<int, int>>) = 0;
    virtual void isValidMove(pair<pair<int, int>, pair<int, int>>) = 0;
};

#endif
