#include <iostream>
#include <SFML/Graphics.hpp>
#include "PTree.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " L N Theta" << std::endl;
        return 1;
    }

    // Parse command-line arguments for the base square size (L) and recursion depth (N)
    double L = std::stod(argv[1]);
    int N = std::stoi(argv[2]);
    double startingAngle = std::stoi(argv[3]);

    // Create a window with dimensions 6L x 4L
    sf::RenderWindow window1(sf::VideoMode(6 * L, 4 * L), "Pythagoras Tree");
    

    window1.setFramerateLimit(60);
    

    PTree tree1(L, N, 45);
    PTree tree2(L, N, startingAngle);

    while (window1.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window1.close();
            }
        }

        window1.clear();
        window1.draw(tree1);
        window1.display();
    }
    sf::RenderWindow window2(sf::VideoMode(10 * L, 4 * L), "Pythagoras Tree");
    window2.setFramerateLimit(60);

    while (window2.isOpen()) {
        sf::Event event;
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window2.close();
            }
        }

        window2.clear();
        window2.draw(tree2);
        window2.display();
    }

    return 0;
}
