#include <iostream>
#include "ch01_algos.hpp"

int main() {
    std::string text;
    std::cin >> text;

    int k;
    std::cin >> k;

    std::map<std::string, int> freqMap = frequencyTable(text, k);

    /* Source:
     * https://stackoverflow.com/questions/6963894/how-to-use-range-based-for-loop-with-stdmap */
    //for (auto& [key, val] : freqMap)
    //    std::cout << key << ": " << val << std::endl;
    for (auto& item : freqMap)
        std::cout << item.first << ": " << item.second << std::endl;

    std::cout << "Max value: " << maxMap(freqMap) << std::endl;
}
