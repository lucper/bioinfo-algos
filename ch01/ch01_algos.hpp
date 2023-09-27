#include <string>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#include <set>

int patternCount(const std::string& text, const std::string& pattern);
std::unordered_set<std::string> frequentWords(const std::string& text, int k);
std::unordered_map<std::string, int> frequencyTable(const std::string& text, int k);
int maxMap(std::unordered_map<std::string, int> freqMap);
std::forward_list<std::string> betterFrequentWords(const std::string& text, int k);
std::string reverseComplement(const std::string& pattern);
std::forward_list<int> patternMatch(const std::string& pattern, const std::string& genome);
std::set<std::string> findClumps(const std::string& genome, int k, int L, int t);
int hammingDist(const std::string& s1, const std::string& s2);
std::forward_list<int> approxPatternMatch(const std::string& pattern, const std::string& text, int d);
