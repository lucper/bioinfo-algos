#include "ch03_algos.hpp"
#include <stdexcept>

std::vector<std::string> kmerComposition(const std::string& text, int k) {
    std::vector<std::string> kmers{};
    for (int i = 0; i < text.length() - k + 1; ++i)
        kmers.push_back(text.substr(i, k));
    return kmers;
}

std::string pathToGenome(const std::vector<std::string>& path) {
    std::string genome = path[0];
    int k = path[0].length();
    for (int i = 1; i < path.size(); ++i)
        genome += path[i].substr(k - 1, 1);
    return genome;
}

std::unordered_map<std::string, std::vector<std::string>> overlapGraph(const std::vector<std::string>& kmers) {
    std::unordered_map<std::string, std::set<std::string>> prefixes{};
    for (auto& kmer : kmers) {
        auto prefix = kmer.substr(0, kmer.length()-1);
        prefixes[prefix].insert(kmer);
    }

    std::unordered_map<std::string, std::vector<std::string>> adj_list{};
    for (auto& kmer : kmers) {
        auto suffix = kmer.substr(1, kmer.length()-1);
        auto adjs = prefixes[suffix];
        adj_list[kmer] = std::vector(adjs.begin(), adjs.end());
    }

    return adj_list;
}
