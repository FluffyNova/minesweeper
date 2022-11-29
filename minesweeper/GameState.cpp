#include "GameState.h"

GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) {
    this->_dimensions = _dimensions;
    this->_numberOfMines = _numberOfMines;
    this->playStatus = PLAYING;
    setBoard();
}

GameState::GameState(const char* filepath) {

    std::ifstream inStream(filepath, std::ios::binary);
    inStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    int width, height, numberOfMines;
    std::vector<int> bytes;

    if(inStream.is_open()) {
        int value;

        while(inStream >> value) {

            if(height == 0) {
                width++;
            }

            // Detecting line break ('\n' == 0x0a)
            if(value == 0x0a) {
                height++;
                continue;
            }

            // Detecting mine (1 == 0b1)
            if(value == 0b1) {
                numberOfMines++;
            }

            bytes.push_back(value);
        }
    } else {
        // Idea from https://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception
        throw std::invalid_argument("File not found");
    }
    inStream.close();

    sf::Vector2i dimensions(width, height);

    this->_dimensions = dimensions;
    this->_numberOfMines = numberOfMines;

    setBoard(bytes);
}


int GameState::getFlagCount() {
    int flagCount = 0;

    for(std::vector<Tile> row : tileBoard) {
        for(Tile tile : row) {
            if(tile.getState() == Tile::FLAGGED) {
                flagCount++;
            }
        }
    }

    return flagCount;
}


int GameState::getMineCount() {
    int mineCount = 0;

    for(std::vector<Tile> row : tileBoard) {
        for(Tile tile : row) {
            if(tile.getIsMine()) {
                mineCount++;
            }
        }
    }

    return mineCount;
}

Tile* GameState::getTile(int x, int y) {
    Tile* tile = nullptr;
    std::vector<std::vector<Tile>> board = this->tileBoard;
    tile = &board[x][y];
    return tile;
}

GameState::PlayStatus GameState::getPlayStatus() {
    return this->playStatus;
}

void GameState::setPlayStatus(PlayStatus _status) {
    this->playStatus = _status;
}

void GameState::setBoard() {
    int width = this->_dimensions.x;
    int height = this->_dimensions.y;
    std::vector<std::vector<int>> board;

    // Create temporary board (1d) to randomize mine position
    int length = width * height;
    int* tempBoard = new int[length](); // zero-initialized
    int tempNumberOfMines = this->_numberOfMines;

    // Randomize mine position
    while(tempNumberOfMines > 0) {
        int position = rand() % length;
        if(tempBoard[position] == 0) {
            tempBoard[position] = 1;
            tempNumberOfMines--;
        }
    }

    int count = 0;

    for(int i=0; i<width; i++) {
        for (int j = 0; j < height; j++) {
            board[i][j] = tempBoard[count];
            count++;
        }
    }

    this->board = board;
    delete[] tempBoard;
}

void GameState::setBoard(std::vector<int> bytes) {
    int width = this->_dimensions.x;
    int height = this->_dimensions.y;
    std::vector<std::vector<int>> board;

    int count = 0;

    for(int i=0; i<width; i++) {
        for (int j = 0; j < height; j++) {
            board[i][j] = bytes[count];
            count++;
        }
    }

    this->board = board;
}

std::vector<std::vector<int>> GameState::getBoard() {
    return this->board;
}

void GameState::setTileBoard(std::vector<std::vector<Tile>> tileBoard) {
    this->tileBoard = tileBoard;
}

std::vector<std::vector<Tile>> GameState::getTileBoard() {
    return this->tileBoard;
}