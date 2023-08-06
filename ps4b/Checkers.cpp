// Copyright [2023] Daniel Olen

#include "Checkers.h"

Checkers::Checkers() {
    loadTextures();
    setupBoard();
    isBlackTurn = true;
}

void Checkers::click(const sf::Vector2f& position) {
    int col = static_cast<int>(position.x) / 64;
    int row = static_cast<int>(position.y) / 64;

    if ((col + row) % 2 == 0) {
        return;
    }

    if (selectedPiece == nullptr) {
        auto pieceIt = findPiece([&](const sf::Sprite& piece) {
            sf::FloatRect bounds = piece.getGlobalBounds();
            return bounds.contains(position);
        });

        if (pieceIt != pieces.end()) {
            PieceType pieceType = getPiece(&(*pieceIt));
            if ((isBlackTurn && (pieceType == PieceType::RedPawn ||
                pieceType == PieceType::RedKing)) ||
                (!isBlackTurn && (pieceType == PieceType::BlackPawn ||
                pieceType == PieceType::BlackKing))) {
                return;
            }
            selectedPiece = &(*pieceIt);
            pieceIt->setColor(sf::Color(255, 255, 255, 128));

            int prevCol = static_cast<int>(selectedPiece->getPosition().x) / 64;
            int prevRow = static_cast<int>(selectedPiece->getPosition().y) / 64;

            highlightValidMoves(prevCol, prevRow);
        }
    } else {
        int prevCol = static_cast<int>(selectedPiece->getPosition().x) / 64;
        int prevRow = static_cast<int>(selectedPiece->getPosition().y) / 64;

        if (isValidMove(prevCol, prevRow, col, row)) {
            movePiece(selectedPiece, col, row);
            // Switch turn after a valid move
            isBlackTurn = !isBlackTurn;
        }
        selectedPiece->setColor(sf::Color::White);
        selectedPiece = nullptr;
        highlightedSquares.clear();
    }
}

std::vector<sf::Sprite>::iterator
Checkers::findPiece(std::function<bool(const sf::Sprite&)> predicate) {
    return std::find_if(pieces.begin(), pieces.end(), predicate);
}

bool Checkers::isValidMove(int prevCol, int prevRow, int newCol, int newRow) {
    PieceType pieceType = getPiece(selectedPiece);

    int colDifference = std::abs(newCol - prevCol);
    int rowDifference = std::abs(newRow - prevRow);

    // Check if the destination square is already occupied
    for (const auto& piece : pieces) {
        int pieceCol = static_cast<int>(piece.getPosition().x) / 64;
        int pieceRow = static_cast<int>(piece.getPosition().y) / 64;
        if (pieceCol == newCol && pieceRow == newRow) {
            return false;
        }
    }

    bool jumpMove = colDifference == 2 && rowDifference == 2;

    if (pieceType == PieceType::RedPawn) {
        // RedPawn can only move up the board
        if (prevRow - newRow == 1 && colDifference == 1) {
            return true;
        }
    } else if (pieceType == PieceType::BlackPawn) {
        // BlackPawn can only move down the board
        if (newRow - prevRow == 1 && colDifference == 1) {
            return true;
        }
    } else if (pieceType == PieceType::RedKing ||
     pieceType == PieceType::BlackKing) {
        // Kings can move in any direction
        if (colDifference == 1 && rowDifference == 1) {
            return true;
        }
    }

    if (jumpMove) {
        int midCol = (prevCol + newCol) / 2;
        int midRow = (prevRow + newRow) / 2;
        PieceType midPieceType = PieceType::None;

        for (const auto& piece : pieces) {
            int pieceCol = static_cast<int>(piece.getPosition().x) / 64;
            int pieceRow = static_cast<int>(piece.getPosition().y) / 64;
            if (pieceCol == midCol && pieceRow == midRow) {
                midPieceType = getPiece(&piece);
                break;
            }
        }

        bool isEnemyPiece = (isBlackTurn && (midPieceType == PieceType::RedPawn
         || midPieceType == PieceType::RedKing)) ||
         (!isBlackTurn && (midPieceType == PieceType::BlackPawn
         || midPieceType == PieceType::BlackKing));

        if (isEnemyPiece) {
            if (pieceType == PieceType::RedPawn) {
                // RedPawn can only jump up the board
                if (prevRow - newRow == 2) {
                    removePiece(sf::Vector2i(midCol, midRow));
                    return true;
                }
            } else if (pieceType == PieceType::BlackPawn) {
                // BlackPawn can only jump down the board
                if (newRow - prevRow == 2) {
                    removePiece(sf::Vector2i(midCol, midRow));
                    return true;
                }
            } else if (pieceType == PieceType::RedKing ||
             pieceType == PieceType::BlackKing) {
                // Kings can jump in any direction
                removePiece(sf::Vector2i(midCol, midRow));
                return true;
            }
        }
    }

    return false;
}

void Checkers::removePiece(sf::Vector2i position) {
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
        int pieceCol = static_cast<int>(it->getPosition().x) / 64;
        int pieceRow = static_cast<int>(it->getPosition().y) / 64;

        if (pieceCol == position.x && pieceRow == position.y) {
            pieces.erase(it);
            break;
        }
    }
}

void Checkers::movePiece(sf::Sprite* piece, int col, int row) {
    piece->setPosition(col * 64, row * 64);

    // Check if a pawn has reached the other side of the board
    PieceType pieceType = getPiece(piece);
    if ((pieceType == PieceType::RedPawn && row == 0) ||
        (pieceType == PieceType::BlackPawn && row == 7)) {
        promoteToKing(piece);
    }
}

void Checkers::promoteToKing(sf::Sprite* piece) {
    PieceType pieceType = getPiece(piece);

    if (pieceType == PieceType::RedPawn) {
        piece->setTexture(redKingTexture);
    } else if (pieceType == PieceType::BlackPawn) {
        piece->setTexture(blackKingTexture);
    }
}

void Checkers::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape square(sf::Vector2f(64, 64));

    sf::RenderTexture renderTexture;
    renderTexture.create(512, 512);
    renderTexture.clear();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                square.setFillColor(sf::Color(255, 0, 0));
            } else {
                square.setFillColor(sf::Color(0, 0, 0));
            }

            square.setPosition(i * 64, j * 64);
            renderTexture.draw(square, states);
        }
    }

    for (const auto& piece : pieces) {
        renderTexture.draw(piece, states);
    }

    for (const auto& highlightedSquare : highlightedSquares) {
        renderTexture.draw(highlightedSquare, states);
    }

    if (selectedPiece != nullptr) {
        renderTexture.draw(*selectedPiece, states);
    }

    renderTexture.display();
    target.draw(sf::Sprite(renderTexture.getTexture()), states);
}



void Checkers::loadTextures() {
    redPawnTexture.loadFromFile("redpawn.png");
    redKingTexture.loadFromFile("redking.png");
    blackPawnTexture.loadFromFile("blackpawn.png");
    blackKingTexture.loadFromFile("blackking.png");
}

void Checkers::setupBoard() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 != 0) {
                sf::Sprite piece;

                if (j < 3) {
                    piece.setTexture(blackPawnTexture);
                } else if (j > 4) {
                    piece.setTexture(redPawnTexture);
                } else {
                    continue;
                }

                piece.setPosition(i * 64, j * 64);
                pieces.push_back(piece);
            }
        }
    }
}

PieceType Checkers::getPiece(const sf::Sprite* piece) {
    if (piece == nullptr) {
        return PieceType::None;
    }

    const sf::Texture* texture = piece->getTexture();

    if (texture == &redPawnTexture) {
        return PieceType::RedPawn;
    } else if (texture == &redKingTexture) {
        return PieceType::RedKing;
    } else if (texture == &blackPawnTexture) {
        return PieceType::BlackPawn;
    } else if (texture == &blackKingTexture) {
        return PieceType::BlackKing;
    } else {
        return PieceType::None;
    }
}

void Checkers::highlightValidMoves(int col, int row) {
    highlightedSquares.clear();
    for (int newCol = 0; newCol < 8; ++newCol) {
        for (int newRow = 0; newRow < 8; ++newRow) {
            if (isValidMoveWithoutRemovingPiece(col, row, newCol, newRow)) {
                sf::RectangleShape square(sf::Vector2f(64, 64));
                square.setFillColor(sf::Color(255, 255, 0, 100));
                square.setPosition(newCol * 64, newRow * 64);
                highlightedSquares.push_back(square);
            }
        }
    }
}

bool Checkers::isValidMoveWithoutRemovingPiece
(int prevCol, int prevRow, int newCol, int newRow) {
    PieceType pieceType = getPiece(selectedPiece);

    int colDifference = std::abs(newCol - prevCol);
    int rowDifference = std::abs(newRow - prevRow);

    // Check if the destination square is already occupied
    for (const auto& piece : pieces) {
        int pieceCol = static_cast<int>(piece.getPosition().x) / 64;
        int pieceRow = static_cast<int>(piece.getPosition().y) / 64;
        if (pieceCol == newCol && pieceRow == newRow) {
            return false;
        }
    }

    bool jumpMove = colDifference == 2 && rowDifference == 2;

    if (pieceType == PieceType::RedPawn) {
        // RedPawn can only move up the board
        if (prevRow - newRow == 1 && colDifference == 1) {
            return true;
        }
    } else if (pieceType == PieceType::BlackPawn) {
        // BlackPawn can only move down the board
        if (newRow - prevRow == 1 && colDifference == 1) {
            return true;
        }
    } else if (pieceType == PieceType::RedKing
    || pieceType == PieceType::BlackKing) {
        // Kings can move in any direction
        if (colDifference == 1 && rowDifference == 1) {
            return true;
        }
    }

    if (jumpMove) {
        int midCol = (prevCol + newCol) / 2;
        int midRow = (prevRow + newRow) / 2;
        PieceType midPieceType = PieceType::None;

        for (const auto& piece : pieces) {
            int pieceCol = static_cast<int>(piece.getPosition().x) / 64;
            int pieceRow = static_cast<int>(piece.getPosition().y) / 64;
            if (pieceCol == midCol && pieceRow == midRow) {
                midPieceType = getPiece(&piece);
                break;
            }
        }

        bool isEnemyPiece = (isBlackTurn && (midPieceType == PieceType::RedPawn
         || midPieceType == PieceType::RedKing)) ||
         (!isBlackTurn && (midPieceType == PieceType::BlackPawn
         || midPieceType == PieceType::BlackKing));

        if (isEnemyPiece) {
            if (pieceType == PieceType::RedPawn) {
                // RedPawn can only jump up the board
                if (prevRow - newRow == 2) {
                    return true;
                }
            } else if (pieceType == PieceType::BlackPawn) {
                // BlackPawn can only jump down the board
                if (newRow - prevRow == 2) {
                    return true;
                }
            } else if (pieceType == PieceType::RedKing
            || pieceType == PieceType::BlackKing) {
                // Kings can jump in any direction
                return true;
            }
        }
    }

    return false;
}
