#include <iostream>
#include "Week1.hpp"

int main() {
    std::string text;
    int k;

    std::cin >> text;
    std::cin >> k;

    //std::unordered_set<std::string> res = frequentWords(text, k);
    std::forward_list<std::string> res = betterFrequentWords(text, k);
    res.reverse();
    for (auto s : res) std::cout << s << " ";
    std::cout << std::endl;
}

