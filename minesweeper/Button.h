#pragma once
#include <SFML/Graphics.hpp>

class Button {
    sf::Vector2f _position;
    std::function<void(void)> _onClick;
    sf::Sprite* _sprite;

public:
    Button(sf::Vector2f _position, std::function<void(void)> _onClick);
    sf::Vector2f getPosition();
    sf::Sprite* getSprite();
    void setSprite(sf::Sprite* _sprite);
    void onClick();
};