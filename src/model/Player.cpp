#include "Player.hpp"

Player::Player(string name):name{name}, score {0} {
//    cout << "Construction of " << *this;
}

Player::~Player() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Player &p) {
    o << "Player: " << p.name << endl;
    return o;
}

void Player::increaseScore(ButinPieceType type) {
    score += UtilityFunctions::getValueFromColor(type);
}

void Player::increaseScore(int amount) {
    score += amount;
}

int Player::getScore() const {
    return score;
}
