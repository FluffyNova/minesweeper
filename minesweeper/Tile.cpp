#include "Tile.h"
#include "Toolbox.h"

Tile::Tile(sf::Vector2f position) {
    this->position = position;
    this->state = HIDDEN;

    this->mineTexture.loadFromFile("P4-data/images/mine.png");
    this->hiddenTexture.loadFromFile("P4-data/images/tile_hidden.png");
    this->revealedTexture.loadFromFile("P4-data/images/tile_revealed.png");
    this->flagTexture.loadFromFile("P4-data/images/flag.png");
}

void Tile::revealNeighbors() {
    for(Tile* tile : this->neighbors) {
        if(tile == nullptr) continue;

        // If the neighbor isn't a bomb, reveal it
        if(!(tile->isMine)) {
            this->state = REVEALED;
        }
    }
}


sf::Vector2f Tile::getLocation() {
    return this->position;
}

Tile::State Tile::getState() {
    return this->state;
}

std::array<Tile*, 8>& Tile::getNeighbors() {
    return this->neighbors;
}

bool Tile::getIsMine() {
    return isMine;
}

void Tile::setState(State _state) {
    this->state = _state;
}

void Tile::setNeighbors(std::array<Tile*, 8> _neighbors) {
    this->neighbors = _neighbors;
}

void Tile::onClickRight() {
    this->state = FLAGGED;
}

void Tile::draw() {
    sf::Sprite sprite;
    sprite.setPosition(this->position);
    Tile::State state = this->state;
    Toolbox* toolbox = &Toolbox::getInstance();

    if(state == REVEALED) {
        sprite.setTexture(this->revealedTexture);
    } else if(state == HIDDEN) {
        sprite.setTexture(this->hiddenTexture);
    } else if(state == FLAGGED) {
        sprite.setTexture(this->flagTexture);
    } else if(state == EXPLODED) {
        sprite.setTexture(this->mineTexture);
    }

    toolbox->window.draw(sprite);
}

