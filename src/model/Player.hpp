#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include "../utilities/Utilities.hpp"
using namespace std;

class Player {
private:
    int score;
public:
    Player(string name);
    Player(const Player &) = delete;

    const string name;

    void increaseScore(ButinPieceType type);
    void increaseScore(int amount);
    void setScore(int newScore);
    int getScore() const;

    virtual ~Player();
    friend ostream &operator<<(ostream &, const Player &);
};

#endif