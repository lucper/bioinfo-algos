#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string s1;
    std::cin >> s1;

    std::string s2;
    std::cin >> s2;

    int dist = hammingDist(s1, s2);
    std::cout << dist << std::endl;
}
