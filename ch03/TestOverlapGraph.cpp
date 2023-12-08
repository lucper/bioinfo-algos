#include "ch03_algos.hpp"
#include <iostream>

int main() {
    std::vector<std::string> kmers{};

    for (std::string kmer; std::cin >> kmer;)
        kmers.push_back(kmer);

    auto adj_list = overlapGraph(kmers);

    for (auto& [k1, v] : adj_list) {
        std::cout << k1 << ": ";
        for (auto& k2 : v)
            std::cout << k2 << " ";
        std::cout << std::endl;
    }
}
