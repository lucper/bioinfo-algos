#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string text;
    std::cin >> text;

    int k;
    std::cin >> k;

    //std::unordered_set<std::string> res = frequentWords(text, k);
    std::forward_list<std::string> res = betterFrequentWords(text, k);
    for (auto s : res) std::cout << s << " ";
    std::cout << std::endl;
}

