#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Tile.h"

class GameState {
    sf::Vector2i _dimensions;
    int _numberOfMines;
    std::vector<std::vector<int>> board;
    std::vector<std::vector<Tile>> tileBoard;

public:
    enum PlayStatus { WIN, LOSS, PLAYING };
    GameState(sf::Vector2i _dimensions = sf::Vector2i(25, 16), int _numberOfMines = 50);
    GameState(const char* filepath);

    int getFlagCount();
    int getMineCount();
    Tile* getTile(int x, int y);
    PlayStatus getPlayStatus();
    void setPlayStatus(PlayStatus _status);
    void setBoard();
    void setBoard(std::vector<int> bytes);
    std::vector<std::vector<int>> getBoard();

    std::vector<std::vector<Tile>> getTileBoard();
    void setTileBoard(std::vector<std::vector<Tile>> tileBoard);

private:
    GameState::PlayStatus playStatus;
};