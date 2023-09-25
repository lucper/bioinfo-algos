#!/usr/bin/env python

def skew(genome):
    diag = [0] * (len(genome) + 1)
    for i, ch in enumerate(genome):
        if ch == 'C':
            diag[i+1] = diag[i] - 1
        elif ch == 'G':
            diag[i+1] = diag[i] + 1
        else:
            diag[i+1] = diag[i]
    return diag

def mins(genome):
    skew_diag = skew(genome)
    minimum = min(skew_diag)
    return [i for i, val in enumerate(skew_diag) if val == minimum]

if __name__ == '__main__':
    import fileinput

    with fileinput.input() as fin:
        genome = fin.readline().strip()

    #print(' '.join([str(i) for i in skew(genome)]))
    print(' '.join([str(i) for i in mins(genome)]))
