#include "RegularTile.h"

RegularTile::RegularTile(sf::Vector2f position) : Tile(position) {
    isMine = false;
}

void RegularTile::onClickLeft() {
    if(this->getState() != FLAGGED)
        this->setState(REVEALED);
}
