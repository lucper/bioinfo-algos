#!/usr/bin/env python

def freq_table(text, k):
    freq_map = dict()
    for i in range(len(text) - k + 1):
        kmer = text[i:i+k]
        if kmer in freq_map:
            freq_map[kmer] += 1
        else:
            freq_map[kmer] = 1
    return freq_map

def find_clumps(genome, k, L, t):
    pats = set()
    for i in range(len(genome) - L + 1):
        window = genome[i:i+L]
        freq_map = freq_table(window, k)
        for key in freq_map:
            if freq_map[key] >= t:
                pats.add(key)
    return pats

def find_clumps2(genome, k, L, t):
    pats = set()
    freqmap = freq_table(genome[:L], k)
    for kmer in freqmap:
        if freqmap[kmer] >= t:
            pats.add(kmer)
    for i in range(1, len(genome) - L + 1):
        freqmap[genome[i-1:i-1+k]]
        kmer = genome[L-k+1:L+1]
        if kmer in freqmap:
            freqmap[kmer] += 1
        else:
            freqmap[kmer] = 1
        if freqmap[kmer] >= t:
            pats.add(kmer)
    return pats

if __name__ == '__main__':
    import fileinput

    with fileinput.input() as fin:
        genome = next(fin).strip()
        params = next(fin)
        k, L, t = [int(p) for p in params.split(' ')]

    print(find_clumps2(genome, k, L, t))
