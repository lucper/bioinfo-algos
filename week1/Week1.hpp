#include <string>
#include <unordered_set>
#include <map>
#include <vector>

int patternCount(const std::string& text, const std::string& pattern);
std::unordered_set<std::string> frequentWords(const std::string& text, int k);
std::map<std::string, int> frequencyTable(const std::string& text, int k);
int maxMap(std::map<std::string, int> freqMap);
std::vector<std::string> betterFrequentWords(const std::string& text, int k);
