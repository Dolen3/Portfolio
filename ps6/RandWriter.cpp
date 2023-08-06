// Copyright [2023] Daniel Olen

#include "RandWriter.h"

RandWriter::RandWriter(std::string text, int k) : text_(text), k_(k) {
    for (size_t i = 0; i < text_.length() - k; ++i) {
        std::string kgram = text_.substr(i, k);
        char next_char = text_[i + k];
        freq_map_[kgram].push_back({next_char, 1});
    }
}

int RandWriter::orderK() const {
    return k_;
}

int RandWriter::freq(std::string kgram) const {
    auto it = freq_map_.find(kgram);
    if (it == freq_map_.end()) {
        return 0;
    }

    int count = 0;
    for (const auto& pair : it->second) {
        count += pair.second;
    }

    return count;
}

int RandWriter::freq(std::string kgram, char c) const {
    auto it = freq_map_.find(kgram);
    if (it == freq_map_.end()) {
        return 0;
    }

    for (const auto& pair : it->second) {
        if (pair.first == c) {
            return pair.second;
        }
    }

    return 0;
}

char RandWriter::kRand(std::string kgram,
                       std::function<int(const std::vector<char>&)> dist_func) {
    auto it = freq_map_.find(kgram);
    if (it == freq_map_.end()) {
        throw std::invalid_argument("Invalid kgram provided");
    }

    std::vector<char> chars;
    for (const auto& pair : it->second) {
        for (int i = 0; i < pair.second; ++i) {
            chars.push_back(pair.first);
        }
    }

    if (!dist_func) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, chars.size() - 1);
        dist_func = [&](const std::vector<char>&) { return dis(gen); };
    }

    return chars[dist_func(chars)];
}

std::string RandWriter::generate(std::string kgram, int L) {
    std::string result = kgram;
    while (static_cast<int>(result.length()) < L) {
        char next_char = kRand(kgram);
        if (next_char == '\0') {
            break;
        }
        result.push_back(next_char);
        kgram = result.substr(result.length() - k_, k_);
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const RandWriter& rw) {
    os << "RandWriter (order " << rw.orderK() << "):\n";
    for (const auto& pair : rw.freq_map_) {
        os << pair.first << ": ";
        for (const auto& freq_pair : pair.second) {
            os << "(" << freq_pair.first << ", " << freq_pair.second << "), ";
        }
        os << "\n";
    }

    return os;
}
