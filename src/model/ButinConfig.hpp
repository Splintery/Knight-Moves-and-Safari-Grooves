#ifndef BUTINCONFIG_HPP
#define BUTINCONFIG_HPP

#include "GameConfig.hpp"

class ButinConfig : public GameConfig {
private:
    virtual ~ButinConfig();
public:
    ButinConfig();
    ButinConfig(const ButinConfig&) = delete;
    vector<pair<int, int>> deleted_pieces;

    friend ostream &operator<<(ostream &, const ButinConfig &);
};



#endif
