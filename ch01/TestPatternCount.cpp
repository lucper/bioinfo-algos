#include <iostream>
#include "Week1.hpp"

int main() {
    std::string text;
    std::string pattern;

    std::cin >> text;
    std::cin >> pattern;

    std::cout << patternCount(text, pattern) << std::endl;
}

