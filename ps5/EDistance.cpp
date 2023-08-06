#include "EDistance.h"
#include <algorithm>

// Copyright [2023] Daniel Olen & Hunter Hasenfus

EDistance::EDistance(const std::string &x, const std::string &y) :
x(x), y(y), opt(x.length() + 1, std::vector<int>(y.length() + 1)) {}

int EDistance::penalty(char a, char b) {
    return a == b ? 0 : 1;
}

int EDistance::min(int a, int b, int c) {
    return std::min(std::min(a, b), c);
}

int EDistance::optDistance() {
    int n = x.length();
    int m = y.length();

    for (int i = 0; i <= n; ++i) {
        opt[i][0] = i * 2;
    }

    for (int j = 0; j <= m; ++j) {
        opt[0][j] = j * 2;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int match = opt[i - 1][j - 1] + penalty(x[i - 1], y[j - 1]);
            int insert = opt[i - 1][j] + 2;
            int delete_ = opt[i][j - 1] + 2;
            opt[i][j] = min(match, insert, delete_);
        }
    }

    return opt[n][m];
}

std::string EDistance::alignment() {
    std::string result;
    int i = x.length(), j = y.length();

    while (i > 0 || j > 0) {
        if (i > 0 && opt[i][j] == opt[i - 1][j] + 2) {
            result = std::string(1, x[i - 1]) +
            " - " + std::to_string(2) + "\n" + result;
            --i;
        } else if (j > 0 && opt[i][j] == opt[i][j - 1] + 2) {
            result = "- " + std::string(1, y[j - 1]) +
            " " + std::to_string(2) + "\n" + result;
            --j;
        } else {
            result = std::string(1, x[i - 1]) + " " + std::string(1, y[j - 1]) +
            " " + std::to_string(penalty(x[i - 1], y[j - 1])) + "\n" + result;
            --i;
            --j;
        }
    }

    return result;
}



