#include <iostream>
#include "esa.hxx"

int esaxx_wrapper(const std::string T,
                  std::vector<int>& SA,
                  std::vector<int>& L,
                  std::vector<int>& R,
                  std::vector<int>& D,
                  int n, int k, int& nodeNum) {

    // 入力の出力
    std::cout << "Input T: " << T << std::endl;
    std::cout << "Input n: " << n << std::endl;
    std::cout << "Input k: " << k << std::endl;

    // 関数が呼び出される前のベクタの出力
    std::cout << "Before processing, SA: ";
    for(const auto & val : SA) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Before processing, L: ";
    for(const auto & val : L) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Before processing, R: ";
    for(const auto & val : R) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Before processing, D: ";
    for(const auto & val : D) std::cout << val << " ";
    std::cout << std::endl;

    // 関数が呼び出される前のイテレータの出力
    std::cout << "Before processing, T.begin(): " << *(T.begin()) << std::endl;
    std::cout << "Before processing, SA.begin(): " << *(SA.begin()) << std::endl;
    std::cout << "Before processing, L.begin(): " << *(L.begin()) << std::endl;
    std::cout << "Before processing, R.begin(): " << *(R.begin()) << std::endl;
    std::cout << "Before processing, D.begin(): " << *(D.begin()) << std::endl;
    
    int err =  esaxx(T.begin(), SA.begin(), L.begin(), R.begin(), D.begin(), n, k, nodeNum);

    // 関数が呼び出された後のベクタの出力
    std::cout << "After processing, SA: ";
    for(const auto & val : SA) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "After processing, L: ";
    for(const auto & val : L) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "After processing, R: ";
    for(const auto & val : R) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "After processing, D: ";
    for(const auto & val : D) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Output nodeNum: " << nodeNum << std::endl;

    return err;
}
