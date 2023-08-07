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

std::forward_list<std::string> betterFrequentWords(const std::string& text, int k) {
    std::map<std::string, int> freqMap = frequencyTable(text, k);
    int max = maxMap(freqMap);
    std::forward_list<std::string> mostFrequents;
    for (auto& [key, val] : freqMap)
        if (val == max)
            mostFrequents.push_front(key);
    mostFrequents.reverse();
    return mostFrequents;
}

std::string reverseComplement(const std::string& pattern) {
    int n = pattern.length();
    std::string revComp;
    for (int i = n - 1; i >= 0; --i)
        if (pattern[i] == 'A')
            revComp += 'T';
        else if (pattern[i] == 'T')
            revComp += 'A';
        else if (pattern[i] == 'C')
            revComp += 'G';
        else if (pattern[i] == 'G')
            revComp += 'C';
    return revComp;
}

std::forward_list<int> patternMatch(const std::string& pattern, const std::string& genome) {
    int count = 0, n = genome.length(), m = pattern.length();
    std::forward_list<int> positions;
    for (int i = 0; i < n - m + 1; ++i) {
        int j = m - 1;
        while (j >= 0 && genome[i + j] == pattern[j])
            j--;
        if (j < 0)
            positions.push_front(i);
    }
    positions.reverse();
    return positions;
}

std::set<std::string> findClumps(const std::string& genome, int k, int L, int t) {
    std::set<std::string> patterns;
    std::map<std::string, int> freqMap = frequencyTable(genome.substr(0, L), k);
    for (auto& [key, val] : freqMap)
        if (val >= t)
            patterns.insert(key);
    for (int i = 1; i < genome.length() - L + 1; ++i) {
        // dont compute the overlapping region again!
        // add or update genome.substr(i + L - k, k)
        std::string kmer = genome.substr(i + L - k, k);
        if (freqMap.find(kmer) == freqMap.end())
            freqMap[kmer] = 1;
        else
            freqMap[kmer]++;
        if (freqMap[kmer] >= t)
            patterns.insert(kmer);
    }
    return patterns;
}
