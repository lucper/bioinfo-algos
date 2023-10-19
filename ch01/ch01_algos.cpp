#include "ch01_algos.hpp"
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

std::unordered_map<std::string, int> frequencyTable(const std::string& text, int k) {
    std::unordered_map<std::string, int> freqMap{};
    for (int i = 0; i < text.length() - k + 1; ++i) {
        std::string pattern = text.substr(i, k);
        freqMap[pattern]++;
    }
    return freqMap;
}

int maxMap(std::unordered_map<std::string, int> freqMap) {
    if (freqMap.empty())
        throw std::invalid_argument("freqMap is empty");
    int max = freqMap.begin()->second;
    for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        if (it->second > max)
            max = it->second;
    return max;
}

std::forward_list<std::string> betterFrequentWords(const std::string& text, int k) {
    std::unordered_map<std::string, int> freqMap = frequencyTable(text, k);
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
    for (int i = 0; i < genome.length() - L + 1; ++i) {
        // dont compute the overlapping region again!
        // add or update genome.substr(i + L - k, k)
        std::string window = genome.substr(i, L);
        std::unordered_map<std::string, int> freqMap = frequencyTable(window, k);
        for (auto& [key, val] : freqMap)
            if (val >= t)
                patterns.insert(key);
    }
    return patterns;
}

int hammingDist(const std::string& s1, const std::string& s2) {
    int dist = 0;
    for (int i = 0; i < s1.length(); ++i)
        if (s1[i] != s2[i])
            dist++;
    return dist;
}

std::pair<int, std::forward_list<int>> approxPatternMatch(const std::string& pattern, const std::string& text, int d) {
    int count = 0, n = text.length(), m = pattern.length();
    std::forward_list<int> positions;
    for (int i = 0; i < n - m + 1; ++i)
        if (hammingDist(pattern, text.substr(i, m)) <= d)
            ++count, positions.push_front(i);
    positions.reverse();
    return std::make_pair(count, positions);
}

std::unordered_set<std::string> dNeighbors(const std::string& pattern, int d) {
    std::unordered_set<std::string> neighbors{}, alphabet{"A", "C", "G", "T"};
    if (d == 0) {
        neighbors.insert(pattern);
        return neighbors;
    }
    if (pattern.length() == 1)
        return alphabet;
    std::string suffixPat = pattern.substr(1, pattern.length() - 1);
    std::unordered_set<std::string> suffixNeighbors = dNeighbors(suffixPat, d);
    for (auto& kmer : suffixNeighbors)
        if (hammingDist(kmer, suffixPat) < d)
            for (auto& x : alphabet)
                neighbors.insert(x + kmer);
        else
            neighbors.insert(pattern[0] + kmer);
    return neighbors;
}

std::forward_list<std::string> frequentWordsWithMismatches(const std::string& text, int k, int d) {
    std::unordered_map<std::string, int> freqMap{};
    std::forward_list<std::string> patterns;
    for (int i = 0; i < text.length() - k + 1; ++i) {
        std::string pattern = text.substr(i, k);
        std::unordered_set<std::string> neighbors = dNeighbors(pattern, d);
        for (auto& neighbor : neighbors) freqMap[neighbor]++;
    }
    int max = maxMap(freqMap);
    for (auto& [key, val] : freqMap)
        if (val == max)
            patterns.push_front(key);
    return patterns;
}

std::forward_list<std::string> frequentWordsWithMismatchesAndRC(const std::string& text, int k, int d) {
    std::unordered_map<std::string, int> freqMap{};
    std::forward_list<std::string> patterns;
    for (int i = 0; i < text.length() - k + 1; ++i) {
        std::string pattern = text.substr(i, k), rc_pattern = reverseComplement(pattern);
        std::unordered_set<std::string> neighbors = dNeighbors(pattern, d), rc_neighbors = dNeighbors(rc_pattern, d);
        for (auto& neighbor : neighbors) freqMap[neighbor]++;
        for (auto& rc_neighbor : rc_neighbors) freqMap[rc_neighbor]++;
    }
    int max = maxMap(freqMap);
    for (auto& [key, val] : freqMap)
        if (val == max)
            patterns.push_front(key);
    return patterns;
}
