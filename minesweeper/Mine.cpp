#include "Mine.h"

Mine::Mine(sf::Vector2f position) : Tile(position) {
    isMine = true;
}

void Mine::onClickLeft() {
    if(this->getState() != FLAGGED)
        this->setState(EXPLODED);
}
