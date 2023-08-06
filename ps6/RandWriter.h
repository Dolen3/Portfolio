// Copyright [2023] Daniel Olen
#pragma once

#ifndef RANDWRITER_h
#define RANDWRITER_h
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <random>
#include <utility>
#include <functional>

class RandWriter {
 public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;
    char kRand(std::string kgram,
               std::function<int(const std::vector<char>&)> dist_func = {});
    std::string generate(std::string kgram, int L);

    friend std::ostream& operator<<(std::ostream& os, const RandWriter& rw);

 private:
    std::string text_;
    int k_;
    std::unordered_map<std::string,
    std::vector<std::pair<char, int>>> freq_map_;
};

#endif
