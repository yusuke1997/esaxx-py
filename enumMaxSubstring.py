import sys
from esa import esaxx

def print_snippet(T, beg, length):
    for i in range(length):
        c = T[beg + i]
        print("_" if c.isspace() else c, end="")

def main():

    T = ''
    orig_len = 0

    for line in sys.stdin:
        T +=line.strip()
        orig_len += len(line.strip())

    # TODO: Call esaxx function and other necessary functions.
    # This portion depends on the esaxx function's Python implementation.
    SA = [0]*len(T)
    L = [0]*len(T)
    R = [0]*len(T)
    D = [0]*len(T)
    
    k = 0x100
    
    # Output
    #print(f"    n: {orig_len}")
    #print(f"alpha: {k}")
    
    # This is a placeholder for the nodeNum as it depends on the esaxx function's implementation.
    node_num = 0
    node_num = esaxx(T, SA, L, R, D, orig_len, k, node_num)
    #if esaxx_py(T, SA, L, R, D, len(T), k, node_num) == -1:
    if node_num == -1:
        return -1
    
    #print(f"node:{node_num}")
    #
    #for i in range(node_num):
    #    print(f"{i}\t{R[i] - L[i]}\t{D[i]}\t", end="")
    #    print_snippet(T, SA[L[i]], D[i])
    #    print()
    #
    #print(SA)
    #print(L)
    #print(R)
    #print(D)
    #print(node_num)


    size = len(T)

    # Record changes in BWT
    rank = [0] * size
    r = 0
    for i in range(size):
        if i == 0 or T[(SA[i] + size - 1) % size] != T[(SA[i - 1] + size - 1) % size]:
            r += 1
        rank[i] = r

    print("count\tlength\tstring")
    # Enumerate maximal partial strings
    for i in range(node_num):
        if D[i] == 0 or (rank[R[i] - 1] - rank[L[i]] == 0):
            continue
        print(f"{R[i] - L[i]}\t{D[i]}\t", end="")
        print_snippet(T, SA[L[i]], D[i])
        print()

    
if __name__ == "__main__":
    main()
