#include "Week1.hpp"
#include <stdexcept>

/* Could use Boyer-Moore so that time complexity goes from
 * O(mn) to O(m + n). */
int patternCount(const std::string& text, const std::string& pattern) {
    int count = 0, n = text.length(), m = pattern.length();
    for (int i = 0; i < n - m + 1; ++i) {
        int j = m - 1;
        while (j >= 0 && text[i + j] == pattern[j])
            j--;
        if (j < 0)
            count++;
    }
    return count;
}

std::unordered_set<std::string> frequentWords(const std::string& text, int k) {
    int count[text.length() - k + 1], max = 0;
    for (int i = 0; i < text.length() - k + 1; ++i) {
        count[i] = patternCount(text, text.substr(i, k));
        if (count[i] > max)
            max = count[i];
    }
    std::unordered_set<std::string> freqPatterns;
    for (int i = 0; i < text.length() - k + 1; ++i)
        if (count[i] == max)
            freqPatterns.insert(text.substr(i, k));
    return freqPatterns;
}

std::map<std::string, int> frequencyTable(const std::string& text, int k) {
    std::map<std::string, int> freqMap;
    for (int i = 0; i < text.length() - k + 1; ++i) {
        std::string pattern = text.substr(i, k);
        if (freqMap.find(pattern) == freqMap.end())
            freqMap[pattern] = 1;
        else
            freqMap[pattern]++;
    }
    return freqMap;
}

int maxMap(std::map<std::string, int> freqMap) {
    if (freqMap.empty())
        throw std::invalid_argument("freqMap is empty");
    int max = freqMap.begin()->second;
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        if (it->second > max)
            max = it->second;
    return max;
}

std::vector<std::string> betterFrequentWords(const std::string& text, k) {
    ;
}