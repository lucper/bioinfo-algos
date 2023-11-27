#include "ch03_algos.hpp"
#include <iostream>

int main() {
    int k;
    std::cin >> k;

    std::string text;
    std::cin >> text;

    auto kmers = kmerComposition(text, k);
    for (auto& kmer : kmers)
        std::cout << kmer << " ";
    std::cout << std::endl;
}
