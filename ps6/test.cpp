// Copyright [2023] Daniel Olen

#include <iostream>
#include "RandWriter.h"

int main() {
    std::string text = "gagggagaggcgagaaa";
    int k = 2;
    RandWriter rw(text, k);

    // Test orderK()
    std::cout << "Order k: " << rw.orderK() << std::endl;

    // Test freq(kgram)
    std::cout << "Frequency of 'ga': " << rw.freq("ga") << std::endl;
    std::cout << "Frequency of 'gg': " << rw.freq("gg") << std::endl;

    // Test freq(kgram, c)
    std::cout << "Frequency of 'ga' followed by 'g': "
     << rw.freq("ga", 'g') << std::endl;
    std::cout << "Frequency of 'ga' followed by 'a': " <<
     rw.freq("ga", 'a') << std::endl;

    // Test kRand(kgram)
    try {
        std::cout <<
         "Random character following 'ga' with custom distribution: "
                  << rw.kRand("ga", [](const std::vector<char>& chars) {
                         std::random_device rd;
                         std::mt19937 gen(rd());
                         std::uniform_int_distribution<>
                          dis(0, chars.size() - 1);
                         return dis(gen);
                     })
                  << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Exception caught: " <<
         e.what() << std::endl;
    }


    // Test generate(kgram, L)
    std::cout << "Generated text of length 10 starting with 'ga': " <<
     rw.generate("ga", 10) << std::endl;

    // Test stream insertion operator
    std::cout << "RandWriter internal state: " << rw << std::endl;

    return 0;
}
