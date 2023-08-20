import sys
from esa import esaxx_py

def get_id(word, word2id):
    if word not in word2id:
        word2id[word] = len(word2id)
    return word2id[word]

def print_snippet(T, beg, length):
    for i in range(length):
        c = T[beg + i]
        print("_" if c.isspace() else c, end="")

def main():

    T = ''
    orig_len = 0

    for line in sys.stdin:
        T +=line.strip()
        orig_len += len(line)

    # TODO: Call esaxx function and other necessary functions.
    # This portion depends on the esaxx function's Python implementation.
    SA = [0]*len(T)
    L = [0]*len(T)
    R = [0]*len(T)
    D = [0]*len(T)
    
    k = 0x100
    
    # Output
    print(f"origN: {orig_len}")
    print(f"    n: {len(T)}")
    print(f"alpha: {k}")
    
    # This is a placeholder for the nodeNum as it depends on the esaxx function's implementation.
    node_num = 0
    #print(T)
    #print(esaxx_py(T.encode(), SA, L, R, D, len(T), k, node_num))
    #print('---------------')
    node_num = esaxx_py(T, SA, L, R, D, len(T), k, node_num)
    #if esaxx_py(T, SA, L, R, D, len(T), k, node_num) == -1:
    if node_num == -1:
        return -1
    
    print(f"node:{node_num}")
    
    for i in range(node_num):
        print(f"{i}\t{R[i] - L[i]}\t{D[i]}\t", end="")
        print_snippet(T, SA[L[i]], D[i])
        print()

    #print(node_num)
    #print(T)
    #print(SA)
    #print(L)
    #print(R)
    #print(D)
        
if __name__ == "__main__":
    main()
