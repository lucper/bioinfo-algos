#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    int k;
    std::cin >> k;

    int d;
    std::cin >> d;

    auto patterns = frequentWordsWithMismatches(pattern, k, d);
    for (auto& pat : patterns)
        std::cout << pat << " ";
    std::cout << std::endl;
}
