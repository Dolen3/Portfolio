// Copyright [2023] Daniel Olen
#include "Sokoban.h"

//Default Constructor, sets all values to null and 0
Sokoban::Sokoban() {
    board = nullptr;
    rows = 0;
    cols = 0;
    groundTexture.loadFromFile("ground_01.png");
    wallTexture.loadFromFile("block_06.png");
    crateTexture.loadFromFile("crate_03.png");
    storageTexture.loadFromFile("ground_04.png");
    playerTexture.loadFromFile("player_05.png");
    vText.loadFromFile("victory.png");
}

//Destructor, goes through the board and deletes the index
Sokoban::~Sokoban() {
    if (board != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }
        delete[] board;
        //set board to null 
        board = nullptr;
    }
}

Sokoban& Sokoban::operator=(const Sokoban& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Free the old board, if any
    if (board != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }
        delete[] board;
        board = nullptr;
    }

    // Copy the dimensions of the new board
    rows = other.rows;
    cols = other.cols;

    // Allocate the new board
    board = new char*[rows];
    for (int i = 0; i < rows; i++) {
        board[i] = new char[cols];
        std::memcpy(board[i], other.board[i], cols);
    }

    return *this;
}

int Sokoban::getRows() const {
    return rows;
}

int Sokoban::getCols() const {
    return cols;
}

const char** Sokoban::getBoard() const {
    return (const char**)board;
}

void Sokoban::draw(sf::RenderTarget & target, sf::RenderStates states) const {
     if (board == nullptr) {
        return;
    }
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            sf::Sprite sprite;
            sf::Sprite sprite2;
            sf::Sprite sprite3;
            sf::Sprite vSprite;

            sprite.setPosition(j * 64, i * 64);
            sprite2.setPosition(j * 64, i * 64);
            sprite3.setPosition(j * 64, i * 64);

            if (board[i][j] == '.') {
                sprite.setTexture(groundTexture);
            } else if (board[i][j] == '#') {
                sprite.setTexture(wallTexture);
            } else if (board[i][j] == 'A') {
                sprite.setTexture(groundTexture);
                sprite2.setTexture(crateTexture);
            } else if (board[i][j] == 'a') {
                sprite.setTexture(storageTexture);
            } else if (board[i][j] == '1') {
                sprite.setTexture(storageTexture);
                sprite2.setTexture(crateTexture);
            } else if (board[i][j] == '@') {
                sprite.setTexture(groundTexture);
                sprite2.setTexture(playerTexture);
            } else if (board[i][j] == '%') {
                sprite.setTexture(groundTexture);
                sprite2.setTexture(storageTexture);
                sprite3.setTexture(playerTexture);
            }
            if (isWon()) {
                vSprite.setTexture(vText);
                vSprite.setPosition(32, 170);
            }
            target.draw(sprite, states);
            target.draw(sprite2, states);
            target.draw(sprite3, states);
            target.draw(vSprite, states);
        }
    }
}


//This is the real board constructor
//Reads from a file and inputs characters in to the board
std::istream& operator>>(std::istream& inStream, Sokoban& s) {
    // Free the old board, if any
    if (s.board != nullptr) {
        for (int i = 0; i < s.rows; i++) {
            delete[] s.board[i];
        }
        delete[] s.board;
    }

    inStream >> s.rows >> s.cols;

    // Allocate the new board
    s.board = new char* [s.rows];
    for (int i = 0; i < s.rows; i++) {
        s.board[i] = new char[s.cols];
    }

    // Read in the board
    for (int i = 0; i < s.rows; i++) {
        for (int j = 0; j < s.cols; j++) {
            inStream >> s.board[i][j];
        }
    }

    return inStream;
}

void Sokoban::movePlayer(Direction direction) {
    if (isWon()) {
        return;
    }
    // Find the player's current position using an algorithm
    int playerRow = -1;
    int playerCol = -1;
    for (int i = 0; i < rows; i++) {
        char* playerPos = std::find(board[i], board[i] + cols, '@');
        if (playerPos != board[i] + cols) {
            playerRow = i;
            playerCol = playerPos - board[i];
            break;
        }
        playerPos = std::find(board[i], board[i] + cols, '%');
        if (playerPos != board[i] + cols) {
            playerRow = i;
            playerCol = playerPos - board[i];
            break;
        }
    }
    int newRow = playerRow, newCol = playerCol;
    switch (direction) {
        case UP:
            newRow--;
            break;
        case LEFT:
            newCol--;
            break;
        case DOWN:
            newRow++;
            break;
        case RIGHT:
            newCol++;
            break;
    }

    // Check if the new position is within the board
    if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) {
        return;
    }

    // Check if the new position is a wall
    if (board[newRow][newCol] == '#') {
        return;
    }

    // Check if the new position is an empty space
    if (board[newRow][newCol] == '.') {
        // Move the player to the new position
        if (board[playerRow][playerCol] == '@') {
            board[playerRow][playerCol] = '.';
        } else if (board[playerRow][playerCol] == '%') {
            board[playerRow][playerCol] = 'a';
        } else {
            board[playerRow][playerCol] = ' ';
        }
        board[newRow][newCol] = '@';
        return;
    }

    // Check if the new position is an Storage Location
    if (board[newRow][newCol] == 'a') {
        // Move the player to the new position
        if (board[playerRow][playerCol] == '@') {
            board[playerRow][playerCol] = '.';
        } else {
            board[playerRow][playerCol] = ' ';
        }
        board[newRow][newCol] = '%';
        return;
    } else if (board[newRow][newCol] == 'A' || board[newRow][newCol] == '1') {
        // Calculate the position of the box after being pushed
        int boxRow = newRow;
        int boxCol = newCol;
        switch (direction) {
            case UP:
                boxRow--;
                break;
            case LEFT:
                boxCol--;
                break;
            case DOWN:
                boxRow++;
                break;
            case RIGHT:
                boxCol++;
                break;
        }

        // Check if the box can be pushed
        if (boxRow < 0 || boxRow >= rows || boxCol < 0 || boxCol >= cols ||
        board[boxRow][boxCol] == '#' ||  board[boxRow][boxCol] == 'A') {
            return;
        }
        // If the next space is a box and the current is the player on a storage locaton
        if (board[newRow][newCol] == 'A' && board[playerRow][playerCol] == '%') {
            board[boxRow][boxCol] = 'A';
            board[newRow][newCol] = '@';
            board[playerRow][playerCol] = 'a';
        } else if (board[newRow][newCol] == 'A') {
            // If the box destination is a storage area
            if (board[boxRow][boxCol] == 'a') {
                board[boxRow][boxCol] = '1';
                board[newRow][newCol] = '@';
                board[playerRow][playerCol] = '.';
            } else {
                board[boxRow][boxCol] = 'A';
                board[newRow][newCol] = '@';
                board[playerRow][playerCol] = '.';
            }
        }

        if (board[newRow][newCol] == '1') {
            board[boxRow][boxCol] = 'A';
            board[newRow][newCol] = '%';
            board[playerRow][playerCol] = '.';
        }
    }
}

bool Sokoban::isWon() const {
    int boxes = 0;
    int storage = 0;
    int boxesOnStorage = 0;
    int emptyStorage = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'A') {
                boxes++;
            } else if (board[i][j] == 'a') {
                storage++;
            } else if (board[i][j] == '1') {
                boxes++;
                storage++;
                boxesOnStorage++;
            } else if (board[i][j] == '%') {
                emptyStorage++;
            }
        }
    }

    return (boxesOnStorage == boxes) && (emptyStorage == 0);
}
