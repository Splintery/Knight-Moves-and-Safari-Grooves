#include "SafariConfig.hpp"

SafariConfig::SafariConfig() {
//    cout << "Construction of SafariConfig" << endl;
}

SafariConfig::SafariConfig(const SafariConfig &) {
    cout << "Copy of SafariConfig" << endl;
}

SafariConfig::~SafariConfig() {
    cout << "Destruction of SafariConfig" << endl;
}

ostream &operator<<(ostream &o, const SafariConfig &) {
    return o;
}