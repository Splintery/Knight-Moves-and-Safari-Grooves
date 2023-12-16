#ifndef BUTINCONFIG_HPP
#define BUTINCONFIG_HPP

#include "../GameConfig.hpp"

class ButinConfig : public GameConfig {
public:
    ButinConfig(const vector<Vector2i> deleted_pieces);
    ButinConfig(const ButinConfig&);
    virtual ~ButinConfig();
    const vector<Vector2i> deleted_pieces;

    friend ostream &operator<<(ostream &, const ButinConfig &);
};

#endif
