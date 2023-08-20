# distutils: language=c++
# -*- coding: utf-8 -*-

# esa.pyx
# $ python setup.py build_ext --inplace

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