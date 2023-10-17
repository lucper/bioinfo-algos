#include <iostream>
#include "ch01_algos.hpp"

int main() {
    auto neighs = dNeighbors("lucas", 2);
    for (auto& neigh : neighs)
        std::cout << neigh << std::endl;
}
