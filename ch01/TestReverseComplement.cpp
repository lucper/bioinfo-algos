#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string pattern;
    std::cin >> pattern;

    std::cout << reverseComplement(pattern) << std::endl;
}
