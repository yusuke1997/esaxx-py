#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "esa.hxx"


int main() {
    std::string T = "banana"; // Input string
    const int n = T.size();   // Length of the input string
    const int k = 256;        // Assuming the input string is ASCII

    std::vector<int> SA(n); // Suffix array
    std::vector<int> L(n);  // Left boundary of internal node
    std::vector<int> R(n);  // Right boundary of internal node
    std::vector<int> D(n);  // Depth of internal node
    int nodeNum = 0;           // Number of internal nodes

    int result = esaxx(T.begin(), SA.begin(), L.begin(), R.begin(), D.begin(), n, k, nodeNum);
    if (result != 0) {
        std::cerr << "Error occurred during ESA computation!" << std::endl;
        return 1;
    }

    std::cout << "Suffix Array (SA): ";
    //for (int i : SA) {
    //    std::cout << i << " ";
    //}
    std::cout << std::endl;

    std::cout << "Number of internal nodes: " << nodeNum << std::endl;

    return 0;
}
