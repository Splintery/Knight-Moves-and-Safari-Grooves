#ifndef BUTINCONFIG_HPP
#define BUTINCONFIG_HPP

#include "GameConfig.hpp"

class ButinConfig : public GameConfig {
private:
    virtual ~ButinConfig();
public:
    ButinConfig();
    ButinConfig(const ButinConfig&) = delete;
    const vector<Vector2i> deleted_pieces;

    friend ostream &operator<<(ostream &, const ButinConfig &);
};



#endif
