#include <iostream>
#include "Week1.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    std::string genome;
    std::cin >> genome;

    std::forward_list<int> res = patternMatch(pattern, genome);
    for (int pos : res)
        std::cout << pos << " ";
    std::cout << std::endl;
}
