#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "esa.hxx"

namespace py = pybind11;

using StringT = std::vector<int>;
using SArrayT = std::vector<int>;
using IndexT = int;

int concrete_esaxx(StringT T, SArrayT SA, SArrayT L, SArrayT R, SArrayT D, IndexT n, IndexT k, IndexT& nodeNum) {
    return esaxx(T, SA, L, R, D, n, k, nodeNum);
}



PYBIND11_MODULE(esa, m) {
    m.doc() = "Python module for esa function";
    m.def("concrete_esaxx", &concrete_esaxx, "A function which computes the enhanced suffix array for specific types");

}

