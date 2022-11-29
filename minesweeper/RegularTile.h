#pragma once
#include "Tile.h"


class RegularTile : public Tile {
public:
    RegularTile(sf::Vector2f position);
    void onClickLeft();
};
