# distutils: language=c++
# -*- coding: utf-8 -*-

# esa.pyx
# $ python setup.py build_ext --inplace

from libcpp.vector cimport vector
from libcpp.string cimport string

cdef extern from "esa_wrapper.hxx":
    int esaxx_wrapper(string T, vector[int]& SA, vector[int]& L, vector[int]& R, vector[int]& D, int n, int k, int& nodeNum)


#def py_esaxx(str s):
#    cdef:
#        string T = s.encode('utf-8')
#        int n = len(s)
#        int k = 256
#        int nodeNum = 0
#        vector[int] SA = vector[int](n)
#        vector[int] L = vector[int](n)
#        vector[int] R = vector[int](n)
#        vector[int] D = vector[int](n)
#
#    res = esaxx_wrapper(T, SA, L, R, D, n, k, nodeNum)
#
#    sa = [SA[i] for i in range(SA.size())]
#    l = [L[i] for i in range(L.size())]
#    r = [R[i] for i in range(R.size())]
#    d = [D[i] for i in range(D.size())]
#
#    return sa, l, r, d, nodeNum, res


#def esaxx_py_copy(string T, vector[int] SA, vector[int] L, vector[int] R, vector[int] D, int n, int k, int nodeNum):
#
#    res = esaxx_wrapper(T, SA, L, R, D, n, k, nodeNum)
#
#    sa = [SA[i] for i in range(SA.size())]
#    l = [L[i] for i in range(L.size())]
#    r = [R[i] for i in range(R.size())]
#    d = [D[i] for i in range(D.size())]
#
#    print(nodeNum)
#    print(SA)
#    print(L)
#    print(R)
#    print(D)
#    
#    #return sa, l, r, d, nodeNum, res
#    return res


def esaxx_py(str T, list SA, list L, list R, list D, int n, int k, int nodeNum):
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