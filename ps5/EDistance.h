#pragma once

#ifndef EDISTANCE_H
#define EDISTANCE_H

// Copyright [2023] Daniel Olen & Hunter Hasenfus

#include <string>
#include <vector>
#include <algorithm>

class EDistance {
 public:
    EDistance(const std::string &x, const std::string &y);

    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int optDistance();
    std::string alignment();

 private:
    std::string x, y;
    std::vector<std::vector<int>> opt;
};

#endif
