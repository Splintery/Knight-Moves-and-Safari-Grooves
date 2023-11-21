#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
using namespace std;

class Player {
public:
    Player(string name);
    Player(const Player &) = delete;
    virtual ~Player();

    const string name;

    friend ostream &operator<<(ostream &, const Player &);
private:
    int score;
};

#endif