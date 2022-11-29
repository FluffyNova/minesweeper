#include "Toolbox.h"

Toolbox::Toolbox() {
    sf::VideoMode mode(800, 600);
    this->window.create(mode, "P4 – Minesweeper, Aidan Burrowes", sf::Style::Default);
    this->gameState = (GameState *) GameState::PLAYING;
    sf::Vector2f p(1, 1);

//    std::function<void(void)> debugFunction = std::bind(Toolbox::onClickDebug(), this, p, debugFunction, &this->debugButton);
//    this->debugButton = new Button(, debugFunction);
//
//    std::function<void(void)> newGameFunction = std::bind();
//    this->newGameButton = new Button(, newGameFunction);
//
//    std::function<void(void)> testButton1Function = std::bind();
//    this->testButton1 = new Button(, testButton1Function);
//
//    std::function<void(void)> testButton2Function = std::bind();
//    this->testButton2 = new Button(, testButton2Function);
}

Toolbox& Toolbox::getInstance() {
    static Toolbox instance;
    return instance;
}

void onClickDebug() {

}

void onClickNewGame() {

}

void onClickTestButton1() {

}

void onClickTestButton2() {

}