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
    virtual ~Player();
    Player(const Player &) = delete;
    Player& operator=(const Player&) = delete;

    const string name;

    void increaseScore(int amount);
    void setScore(int newScore);
    int getScore() const;

    friend ostream &operator<<(ostream &, const Player &);
};

#endif