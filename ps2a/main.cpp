// Copyright [2023] Daniel Olen
#include <iostream>
#include <fstream>
#include "/mnt/d/comp4/ps2a/Sokoban.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <level file>" << std::endl;
        return 1;
    }

    std::string levelFile(argv[1]);
    std::ifstream inFile(levelFile);
    if (inFile) {
        Sokoban game;
        inFile >> game;
        inFile.close();
        sf::RenderWindow window(sf::VideoMode(game.getCols() * 64,
            game.getRows() * 64), "Sokoban");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(game);
            window.display();
        }
    } else {
        std::cout << "Error opening file." << std::endl;
    }
    return 0;
}
