#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <array>
#include <iostream>
using namespace std;


#include "Player.hpp"
#include "Board.hpp"
#include "GameConfig.hpp"

template<typename BoardType, typename ConfigType>
class Game {
protected:
    Player* currentPlayer;
    virtual void isValidMove(const Vector2i& from, const Vector2i& to) const = 0;
public:
    vector<Player*> player_list;
    BoardType* board;
    virtual void start() = 0;
    virtual void end() = 0;
    virtual bool isGameDone() const = 0;
    virtual void initializeGame(const ConfigType &) = 0;
    virtual void makeMove(const Vector2i& from, const Vector2i& to) = 0;
    virtual const vector<Vector2i> validMoves(const Vector2i& from) const = 0;
    virtual const string getCurrentPlayer() const = 0;
    virtual const vector<vector<string>> getBoardState() const = 0;
};

#endif
