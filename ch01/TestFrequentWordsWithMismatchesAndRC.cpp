#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    int k;
    std::cin >> k;

    int d;
    std::cin >> d;

    auto patterns = frequentWordsWithMismatchesAndRC(pattern, k, d);
    for (auto& pattern : patterns)
        std::cout << pattern << " ";
    std::cout << std::endl;
}
