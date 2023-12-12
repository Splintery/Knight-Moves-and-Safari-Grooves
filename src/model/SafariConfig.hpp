#ifndef SAFARICONFIG_HPP
#define SAFARICONFIG_HPP

#include "GameConfig.hpp"

class SafariConfig : public GameConfig {
public:
    SafariConfig();
    SafariConfig(const SafariConfig&);
    virtual ~SafariConfig();
    const vector<Vector2i> crocodiles;
    const vector<Vector2i> elephants;
    const vector<Vector2i> lions;
    const vector<Vector2i> fences;

    friend ostream &operator<<(ostream &, const SafariConfig &);
};

#endif
