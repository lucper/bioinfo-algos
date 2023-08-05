#include <iostream>
#include "Week1.hpp"

int main() {
    std::string text;
    int k;

    std::cin >> text;
    std::cin >> k;

    std::unordered_set<std::string> res = frequentWords(text, k);
    for (auto s : res) std::cout << s << std::endl;
}

