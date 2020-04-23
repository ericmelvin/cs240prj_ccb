// Program input and output
#include <iomanip>
#include <iostream>
#include <vector>
#include "io.hh"


// Main for testing only
int main() {
    std::vector<int> v = genInputNumbers(100, 100000);
    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}

// Generate a vector of random numbers for input to data structures
// Input length: length of vector
// Input max: maximum value in vector
std::vector<int> genInputNumbers(int length, int max) {
    std::vector<int> v;
    for (int i=0; i<length; i++) {
        v.push_back(rand() % max);
    }
    return v;
}