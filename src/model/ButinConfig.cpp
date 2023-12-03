#include "ButinConfig.hpp"

ButinConfig::ButinConfig(const vector<Vector2i> deleted_pieces):deleted_pieces {deleted_pieces} {
    cout << "Construction of ButinConfig" << endl;
}

ButinConfig::ButinConfig(const ButinConfig &) {
    cout << "Copy of ButinConfig" << endl;
}

ButinConfig::~ButinConfig() {
    cout << "Destruction of ButinConfig" << endl;
}

ostream &operator<<(ostream &o, const ButinConfig &bc) {
    return o;
}
