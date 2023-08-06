// Copyright [2023] Daniel Olen

#include <SFML/Graphics.hpp>
#include "Checkers.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "Checkers");
    Checkers checkers;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                checkers.click(window.mapPixelToCoords(sf::Vector2i
                (event.mouseButton.x, event.mouseButton.y)));
            }
        }

        window.clear();
        window.draw(checkers);
        window.display();
    }

    return 0;
}
