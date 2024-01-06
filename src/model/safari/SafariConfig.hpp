#ifndef SAFARICONFIG_HPP
#define SAFARICONFIG_HPP

#include "../GameConfig.hpp"

class SafariConfig : public GameConfig {
public:
    SafariConfig();
    virtual ~SafariConfig();
    SafariConfig(const SafariConfig&);

    vector<Vector2i> crocodiles;
    vector<Vector2i> elephants;
    vector<Vector2i> lions;
    vector<Vector2i> fences;

    friend ostream &operator<<(ostream &, const SafariConfig &);
};

#endif
