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

std::unordered_map<std::string, std::forward_list<std::string>> overlapGraph(const std::vector<std::string>& kmers) {
    std::unordered_map<std::string, std::vector<std::string>> kmer_comp{};
    for (auto& kmer : kmers)
        kmer_comp[kmer] = kmerComposition(kmer, kmer.length()-1);

    std::unordered_map<std::string, std::forward_list<std::string>> adj_list{};
    for (auto& [kmer1, comp1] : kmer_comp) {
        auto suffix = comp1.at(1);
        for (auto& [kmer2, comp2] : kmer_comp) {
            auto prefix = comp2.at(0);
            if (suffix == prefix) adj_list[kmer1].push_front(kmer2);
        }
    }

    return adj_list;
}
