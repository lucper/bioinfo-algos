#include "ch03_algos.hpp"
#include <stdexcept>

std::vector<std::string> kmerComposition(const std::string& text, int k) {
    std::vector<std::string> kmers{};
    for (int i = 0; i < text.length() - k + 1; ++i)
        kmers.push_back(text.substr(i, k));
    return kmers;
}

std::string pathToGenome(const std::vector<std::string>& path) {
    std::string genome = path[0];
    int k = path[0].length();
    for (int i = 1; i < path.size(); ++i)
        genome += path[i].substr(k - 1, 1);
    return genome;
}
