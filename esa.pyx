# distutils: language=c++
# -*- coding: utf-8 -*-

# esa.pyx
# $ python setup.py build_ext --inplace

from collections import namedtuple
from libcpp.vector cimport vector
from libcpp.string cimport string

cdef extern from "esa_wrapper.hxx":
    int esaxx_wrapper(string T, vector[int]& SA, vector[int]& L, vector[int]& R, vector[int]& D, int n, int k, int& nodeNum)

def esaxx(str T, list SA, list L, list R, list D, int n, int k, int nodeNum):
    cdef:
        string s = T.encode('utf-8')
        vector[int] c_SA = SA
        vector[int] c_L = L
        vector[int] c_R = R
        vector[int] c_D = D

    res = esaxx_wrapper(s, c_SA, c_L, c_R, c_D, n, k, nodeNum)

    # Convert back to Python lists
    SA[:] = c_SA
    L[:] = c_L
    R[:] = c_R
    D[:] = c_D

    #return res#, SA, L, R, D, nodeNum
    if res==0:
        return nodeNum
    else:
        return res

def get_maximal_substrings(str T):
    SA = [0]*len(T)
    L = [0]*len(T)
    R = [0]*len(T)
    D = [0]*len(T)
    n = len(T)
    k = 0x10000
    node_num = 0
    node_num = esaxx(T, SA, L, R, D, n, k, node_num)
    if node_num == -1:
        exit(node_num)

    size = len(T)

    # Record changes in BWT
    rank = [0] * size
    r = 0
    for i in range(size):
        if i == 0 or T[(SA[i] + size - 1) % size] != T[(SA[i - 1] + size - 1) % size]:
            r += 1
        rank[i] = r

    # Define the named tuple
    MaximalSubstring = namedtuple('MaximalSubstring', ['count', 'length', 'string'])
    # Override the __str__ method to display only 'string' when printed
    def _substring_repr(self):
        return self.string
    MaximalSubstring.__repr__ = _substring_repr

    # store maximal substring
    substrings = []
    for i in range(node_num):
        if D[i] == 0 or (rank[R[i] - 1] - rank[L[i]] == 0):
            continue
        count = R[i] - L[i]
        length = D[i]

        string = ''
        for j in range(D[i]):
            c = T[SA[L[i]] + j]
            string+= "_" if c.isspace() else c
        substrings.append(MaximalSubstring(count, length, string))

    return substrings
