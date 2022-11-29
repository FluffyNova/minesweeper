#include "Button.h"

Button::Button(sf::Vector2f _position, std::function<void(void)> _onClick) {
    this->_position = _position;
    this->_onClick = _onClick;
}

sf::Vector2f Button::getPosition() {
    return _position;
}

sf::Sprite* Button::getSprite() {
    return this->_sprite;
}

void Button::setSprite(sf::Sprite* _sprite) {
    this->_sprite = _sprite;
}

void Button::onClick() {
    this->_onClick();
}