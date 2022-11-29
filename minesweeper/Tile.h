#pragma once
#include <array>
#include <SFML/Graphics.hpp>

class Tile {
protected:
    sf::Vector2f position;
    std::array<Tile*, 8> neighbors;
    bool isMine;
    void revealNeighbors();
    sf::Texture mineTexture, hiddenTexture, revealedTexture, flagTexture;

public:
    enum State { REVEALED, HIDDEN, FLAGGED, EXPLODED };
    Tile(sf::Vector2f position);
    sf::Vector2f getLocation();
    State getState();
    std::array<Tile*, 8>& getNeighbors();
    bool getIsMine();
    void setState(State _state);
    void setNeighbors(std::array<Tile*, 8> _neighbors);
    virtual void onClickLeft() {};
    void onClickRight();
    void draw();

protected:
    Tile::State state;
};