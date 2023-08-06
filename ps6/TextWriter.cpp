// Copyright [2023] Daniel Olen

#include <iostream>
#include <fstream>
#include "RandWriter.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] <<
         " <order> <output length> <input file>\n";
        return 1;
    }

    int order = std::stoi(argv[1]);
    int output_length = std::stoi(argv[2]);
    std::ifstream input(argv[3]);

    if (!input) {
        std::cerr << "Error: cannot open input file " << argv[3] << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(input)),
     std::istreambuf_iterator<char>());
    std::string seed = text.substr(0, order);

    RandWriter rand_writer(text, order);
    std::string generated_text = rand_writer.generate(seed, output_length);

    std::cout << "Generated text: " << generated_text << std::endl;

    return 0;
}
