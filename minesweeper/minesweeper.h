#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbox.h"
#include "Tile.h"
#include "RegularTile.h"
#include "Mine.h"

bool debugMode = false;

int launch();
void restart();
void render();
void toggleDebugMode();
bool getDebugMode();
int gameLoop();
std::vector<std::vector<Tile>> createBoard(GameState* gameState, int length, int width);
std::vector<std::vector<Tile>> setNeighbors(std::vector<std::vector<Tile>> board);