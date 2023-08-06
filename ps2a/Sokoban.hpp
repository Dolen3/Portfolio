#pragma once
// Copyright [2023] Daniel Olen

#ifndef SOKOBAN_HPP
#define SOKOBAN_HPP

#include <iostream>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Sokoban: public sf::Drawable {
 public:
    Sokoban();
    ~Sokoban();

    int getRows() const;
    int getCols() const;
    const char** getBoard() const;

    friend std::istream& operator>>(std::istream& inStream, Sokoban& game);

 private:
    int rows, cols;
    char** board;
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
    sf::Texture groundTexture;
    sf::Texture wallTexture;
    sf::Texture crateTexture;
    sf::Texture storageTexture;
    sf::Texture playerTexture;
};
#endif
