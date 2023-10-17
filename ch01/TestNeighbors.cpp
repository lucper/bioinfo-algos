#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    int d;
    std::cin >> d;

    auto neighs = dNeighbors(pattern, d);
    for (auto& neigh : neighs)
        std::cout << neigh << " ";
    std::cout << std::endl;
}
