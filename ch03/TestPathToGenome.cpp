#include "ch03_algos.hpp"
#include <iostream>

int main() {
    std::vector<std::string> path{};

    for (std::string kmer; std::cin >> kmer;)
        path.push_back(kmer);

    std::cout << pathToGenome(path) << std::endl;
}
