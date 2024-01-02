#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include "../utilities/Utilities.hpp"
using namespace std;

class Player {
public:
    Player(string name);
    Player(const Player &) = delete;
    virtual ~Player();

    const string name;
    void increaseScore(ButinPieceType type);
    void increaseScore(int amount);
    void setScore(int newScore);

    friend ostream &operator<<(ostream &, const Player &);
    int getScore() const;
private:
    int score;
};

#endif