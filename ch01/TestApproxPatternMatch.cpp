#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    std::string text;
    std::cin >> text;

    int d;
    std::cin >> d;

    auto [count, occurs] = approxPatternMatch(pattern, text, d);
    for (int i : occurs) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << count << std::endl;
}
