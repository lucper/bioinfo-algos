#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string genome;
    std::cin >> genome;

    int k;
    std::cin >> k;

    int L;
    std::cin >> L;

    int t;
    std::cin >> t;

    std::set<std::string> patterns = findClumps(genome, k, L, t);
    for (auto& s : patterns)
        std::cout << s << " ";
    std::cout << std::endl;

    std::cout << patterns.size() << std::endl;
}
