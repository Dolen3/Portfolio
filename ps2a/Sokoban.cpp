// Copyright [2023] Daniel Olen
#include "/mnt/d/comp4/ps2a/Sokoban.hpp"

Sokoban::Sokoban() {
    board = nullptr;
    rows = 0;
    cols = 0;
    groundTexture.loadFromFile("ground_01.png");
    wallTexture.loadFromFile("block_06.png");
    crateTexture.loadFromFile("crate_03.png");
    storageTexture.loadFromFile("ground_04.png");
    playerTexture.loadFromFile("player_05.png");
}

Sokoban::~Sokoban() {
    if (board != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }
        delete[] board;
    }
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
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            sf::Sprite sprite;
            sf::Sprite sprite2;

            sprite.setPosition(j * 64, i * 64);
            sprite2.setPosition(j * 64, i * 64);

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
                sprite.setTexture(crateTexture);
                sprite2.setTexture(storageTexture);
            } else if (board[i][j] == '@') {
                sprite.setTexture(groundTexture);
                sprite2.setTexture(playerTexture);
            }
            target.draw(sprite, states);
            target.draw(sprite2, states);
        }
    }
}

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
