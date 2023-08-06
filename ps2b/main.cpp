// Copyright [2023] Daniel Olen
#include <iostream>
#include <fstream>
#include "Sokoban.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <level file>" << std::endl;
        return 1;
    }
    float keyboardBuffer = 0;
    sf::Music music;
    music.openFromFile("victoryRoyale.ogg");
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

            if (game.isWon() && music.getStatus() != sf::SoundSource::Playing) {
            music.play();
            } else if (!game.isWon()) {
                music.stop();
            }

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && keyboardBuffer >= 5) {
                    inFile.open(levelFile);
                    inFile >> game;
                    inFile.close();
                    music.stop();
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && keyboardBuffer >= 5) {
                    game.movePlayer(UP);
                    keyboardBuffer = 0;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && keyboardBuffer >= 5) {
                    game.movePlayer(LEFT);
                    keyboardBuffer = 0;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && keyboardBuffer >= 5) {
                    game.movePlayer(DOWN);
                    keyboardBuffer = 0;
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && keyboardBuffer >= 5) {
                    game.movePlayer(RIGHT);
                    keyboardBuffer = 0;
                } else if (event.type == sf::Event::KeyPressed && event.key.code
                == sf::Keyboard::R) {
                    inFile.open(levelFile);
                    inFile >> game;
                    inFile.close();
                }
            }
            window.clear();
            window.draw(game);
            window.display();
            keyboardBuffer += 0.5;
        }
    } else {
        std::cout << "Error opening file." << std::endl;
    }
    return 0;
}
