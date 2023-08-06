#pragma once

#ifndef CHECKERS_H
#define CHECKERS_H

// Copyright [2023] Daniel Olen

#include <vector>
#include <algorithm>
#include <functional>
#include <SFML/Graphics.hpp>

enum class PieceType {
RedPawn,
   RedKing,
   BlackPawn,
   BlackKing,
   None
};

class Checkers : public sf::Drawable {
 public:
Checkers();
void click(const sf::Vector2f& position);
PieceType getPiece(const sf::Sprite* piece);
void removePiece(sf::Vector2i position);
void promoteToKing(sf::Sprite* piece);
std::vector<sf::Sprite>::iterator findPiece
(std::function<bool(const sf::Sprite&)> predicate);
void highlightValidMoves(int col, int row);
bool isValidMoveWithoutRemovingPiece
(int prevCol, int prevRow, int newCol, int newRow);

 private:
void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
void loadTextures();
void setupBoard();
bool isValidMove(int prevCol, int prevRow, int newCol, int newRow);
void movePiece(sf::Sprite* piece, int col, int row);

sf::Texture redPawnTexture;
sf::Texture redKingTexture;
sf::Texture blackPawnTexture;
sf::Texture blackKingTexture;

std::vector<sf::Sprite> pieces;
sf::Sprite* selectedPiece = nullptr;

bool isBlackTurn;

std::vector<sf::RectangleShape> highlightedSquares;
};

#endif
