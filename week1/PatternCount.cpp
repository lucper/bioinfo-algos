#include <iostream>
#include <string>
#include <unordered_set>

/* Could use Boyer-Moore so that time complexity goes from
 * O(mn) to O(m + n). */
int patternCount(const std::string& text, const std::string& pattern) {
    int count = 0, n = text.length(), m = pattern.length();
    for (int i = 0; i < n - m + 1; ++i) {
        int j = m - 1;
        while (j >= 0 && text[i + j] == pattern[j])
            j--;
        if (j < 0) {
            std::cout << i << std::endl;
            count++;
        }
    }
    return count;
}

std::unordered_set<std::string> mostFrequent(const std::string& text, int k) {
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

int main() {
    std::string text;
    std::string pattern;

    std::cin >> text;
    std::cin >> pattern;

    std::cout << patternCount(text, pattern) << std::endl;

    std::unordered_set<std::string> res = mostFrequent(text, 3);
    for (auto s : res) std::cout << s << std::endl;
}
