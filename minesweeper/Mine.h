#pragma once
#include "Tile.h"


class Mine : public Tile {
public:
    Mine(sf::Vector2f position);
    void onClickLeft();
};
