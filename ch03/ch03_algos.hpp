#include <string>
#include <vector>
#include <unordered_map>
#include <forward_list>

std::vector<std::string> kmerComposition(const std::string& text, int k);
std::string pathToGenome(const std::vector<std::string>& kmers);
std::unordered_map<std::string, std::forward_list<std::string>> overlapGraph(const std::vector<std::string>& kmers);
