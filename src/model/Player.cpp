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
    score += ButinPiece::getValueFromColor(type);
}

int Player::getScore() const {
    return score;
}
