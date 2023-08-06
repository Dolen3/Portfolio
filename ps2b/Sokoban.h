#pragma once
// Copyright [2023] Daniel Olen

#ifndef SOKOBAN_HPP
#define SOKOBAN_HPP

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <algorithm>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum direction { UP, LEFT, DOWN, RIGHT };
typedef enum direction Direction;

class Sokoban : public sf::Drawable, sf::Music {
 public:
 //2d board constructor
  Sokoban();
  ~Sokoban();
  Sokoban& operator=(const Sokoban& other);
  int getRows() const;
  int getCols() const;
  const char** getBoard() const;

  friend std::istream& operator>>(std::istream& inStream, Sokoban& game);

  void movePlayer(Direction direction);

  bool isWon() const;

 private:
  int rows, cols;
  //2D Character array
  char** board;
  virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
  sf::Texture groundTexture;
  sf::Texture wallTexture;
  sf::Texture crateTexture;
  sf::Texture storageTexture;
  sf::Texture playerTexture;
  sf::Texture vText;
};
#endif
