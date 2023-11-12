#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
using namespace std;

#include "Player.hpp"
#include "Board.hpp"

class Game {
public:
    virtual void init_game() = 0;
protected:
    vector<Player*> player_list;
    Board *board;
};

#endif
