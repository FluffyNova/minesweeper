#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

// Idea from https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c

class Toolbox {
    Toolbox();

public:
    sf::RenderWindow window;
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;

    static Toolbox& getInstance();
    void onClickDebug();
    void onClickNewGame();
    void onClickTestButton1();
    void onClickTestButton2();
};