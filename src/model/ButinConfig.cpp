#include "ButinConfig.hpp"

ButinConfig::ButinConfig() {
    cout << "Construction of ButinConfig" << endl;
}

ButinConfig::~ButinConfig() {
    cout << "Construction of ButinConfig" << endl;
}

ostream &operator<<(ostream &o, const ButinConfig &bc) {
    return o;
}

