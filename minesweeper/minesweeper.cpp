#include "minesweeper.h"

sf::Texture mineTexture, tile_hiddenTexture, tile_revealedTexture, number_1Texture, number_2Texture,
        number_3Texture, number_4Texture, number_5Texture, number_6Texture, number_7Texture, number_8Texture,
        flagTexture, face_happyTexture, face_winTexture, face_loseTexture, digitsTexture, debugTexture, test_1Texture,
        test_2Texture;

int launch() {
    // Load textures
    mineTexture.loadFromFile("P4-data/images/mine.png");
    tile_hiddenTexture.loadFromFile("P4-data/images/tile_hidden.png");
    tile_revealedTexture.loadFromFile("P4-data/images/tile_revealed.png");
    number_1Texture.loadFromFile("P4-data/images/number_1.png");
    number_2Texture.loadFromFile("P4-data/images/number_2.png");
    number_3Texture.loadFromFile("P4-data/images/number_3.png");
    number_4Texture.loadFromFile("P4-data/images/number_4.png");
    number_5Texture.loadFromFile("P4-data/images/number_5.png");
    number_6Texture.loadFromFile("P4-data/images/number_6.png");
    number_7Texture.loadFromFile("P4-data/images/number_7.png");
    number_8Texture.loadFromFile("P4-data/images/number_8.png");
    flagTexture.loadFromFile("P4-data/images/flag.png");
    face_happyTexture.loadFromFile("P4-data/images/face_happy.png");
    face_winTexture.loadFromFile("P4-data/images/face_win.png");
    face_loseTexture.loadFromFile("P4-data/images/face_lose.png");
    digitsTexture.loadFromFile("P4-data/images/digits.png");
    debugTexture.loadFromFile("P4-data/images/debug.png");
    test_1Texture.loadFromFile("P4-data/images/test_1.png");
    test_2Texture.loadFromFile("P4-data/images/test_2.png");

    // Create Toolbox
    Toolbox& toolbox = Toolbox::getInstance();
    GameState* gameState = toolbox.gameState;

    // Create the initial, default board
    std::vector<std::vector<int>> binaryBoard = gameState->getBoard();

    // Idea from https://stackoverflow.com/questions/19894686/getting-size-of-array-from-pointer-c
    int length = sizeof(binaryBoard) / sizeof(binaryBoard[0]);
    int width = sizeof(binaryBoard[0]) / sizeof(binaryBoard[0][0]);

    std::vector<std::vector<Tile>> board =  createBoard(gameState, length, width);

    // Set neighbors of each tile
    board = setNeighbors(board);

    toolbox.gameState->setTileBoard(board);

    gameLoop();

    return 0;
}

int gameLoop() {
    // Window from toolbox
    Toolbox& toolbox = Toolbox::getInstance();
    sf::RenderWindow* window = &toolbox.window;

    while(window->isOpen()) {
        sf::Event event;

        while(window->pollEvent(event)) {
            // Close window
            if(event.type == sf::Event::Closed) {
                window->close();
            }
            if(event.type == sf::Event::MouseButtonPressed) {

            }
        }

        // Render
        render();

    }
    window->display();

    return 0;
}

void restart() {

}

void render() {
    // Render in board
    Toolbox& toolbox = Toolbox::getInstance();
    std::vector<std::vector<Tile>> board = toolbox.gameState->getTileBoard();

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            Tile* tile = &board[i][j];
            tile->draw();
        }
    }

}

void toggleDebugMode() {
    debugMode = !debugMode;
}

bool getDebugMode() {
    return debugMode;
}

std::vector<std::vector<Tile>> createBoard(GameState* gameState, int length, int width) {
    std::vector<std::vector<int>> binaryBoard = gameState->getBoard();
    std::vector<std::vector<Tile>> board;

    // Note screen dimensions are always 400x600
    float tileWidth = 400.0f/length;
    sf::Vector2f tileSize(tileWidth, tileWidth);

    for(int i=0; i<length; i++) {
        for(int j=0; j<width; j++) {
            // If Tile is Regular Tile
            if(binaryBoard[i][j] == 0) {
                board[i][j] = RegularTile(tileSize);
            }

            // If Tile is Mine
            else {
                board[i][j] = Mine(tileSize);
            }
        }
    }

    return board;
}

std::vector<std::vector<Tile>> setNeighbors(std::vector<std::vector<Tile>> board) {
    // Set up arrays for all 8 directions
    int dirX[]{-1, -1, -1,  0, 0, 1, 1, 1};
    int dirY[]{-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[0].size(); j++) {
            // Set neighbors of current Tile
            std::array<Tile*, 8> neighbors;

            for(int k=0; k<8; k++) {
                int currX = i + dirX[k];
                int currY = i + dirY[k];

                // If out of bounds
                if(currX < 0 || currX > board.size() || currY < 0 || currY > board[0].size()) {
                    neighbors[k] = nullptr;
                } else {
                    neighbors[k] = &board[currX][currY];
                }
            }

            board[i][j].setNeighbors(neighbors);
        }
    }

    return board;
}

int main() {
    launch();
    return 0;
}
