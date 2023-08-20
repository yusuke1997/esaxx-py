#include <iostream>
#include "esa.hxx"

int esaxx_wrapper(const std::string T,
                  std::vector<int>& SA,
                  std::vector<int>& L,
                  std::vector<int>& R,
                  std::vector<int>& D,
                  int n, int k, int& nodeNum) {
    
    int err =  esaxx(T.begin(), SA.begin(), L.begin(), R.begin(), D.begin(), n, k, nodeNum);

    return err;
}
