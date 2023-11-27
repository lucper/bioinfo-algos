#include "ch03_algos.hpp"
#include <stdexcept>

std::vector<std::string> kmerComposition(const std::string& text, int k) {
    std::vector<std::string> kmers{};
    for (int i = 0; i < text.length() - k + 1; ++i)
        kmers.push_back(text.substr(i, k));
    return kmers;
}
