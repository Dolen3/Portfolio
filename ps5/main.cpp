#include <iostream>
#include <fstream>
#include <SFML/System.hpp>
#include "EDistance.h"

// Copyright [2023] Daniel Olen & Hunter Hasenfus

int main(int argc, char *argv[]) {
    sf::Clock clock;
    sf::Time t;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string input_file = argv[1];
    std::ifstream infile(input_file);

    if (!infile) {
        std::cerr << "Error: Unable to open input file" << std::endl;
        return 1;
    }

    std::string x, y;
    std::getline(infile, x);
    std::getline(infile, y);
    infile.close();

    EDistance eDistance(x, y);
    int distance = eDistance.optDistance();
    std::string alignment_str = eDistance.alignment();

    std::cout << "Edit distance = " << distance << std::endl;
    std::cout << alignment_str;

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";

    return 0;
}
