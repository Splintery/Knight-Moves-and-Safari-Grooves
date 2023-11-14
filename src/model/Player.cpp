#include "Player.hpp"

Player::Player(string name):_name{name}, score {0} {
    cout << "Construction of " << this;
}

Player::~Player() {
    cout << "Destruction of " << this;
}

ostream &operator<<(ostream &o, const Player &p) {
    o << "Player: " << p._name << endl;
    return o;
}