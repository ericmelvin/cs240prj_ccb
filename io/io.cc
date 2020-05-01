// Program input and output
#include <iomanip>
#include <iostream>
#include <vector>
#include "io.hh"
#include "graph.hh"
// Main for testing only
int main() {

    makeGraph();
    // Testing for generate input numbers
    std::vector<int> v = genInputNumbers(100, 100000);
    for (int i=0; i<v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    // Testing for output table
    std::vector<std::string> h = {"Data Structure", "Size", "buildTree()", "findMin()", "findMax()", "findK()"};

    std::vector<std::vector<double>> timingData = {{1, 2, 3.1, 4.5, 5},
                                {5.1235, 7.835, 189.383, 15.5, 1}};
    std::vector<std::string> rowLabels = {"BST", "RBT"};
    outputTable(timingData, h, rowLabels);

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

// Return milliseconds since epoch time
unsigned long getCurrentTime()  {
    const auto clock = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(
                   clock.time_since_epoch()).count();
}

// Ouput table functions -------------------------------------------------------
// Ouput full table
void outputTable(std::vector<std::vector<double>> timingData, std::vector<std::string> colLabels, std::vector<std::string> rowLabels) {
    int precision = 10;
    outputColLabels(colLabels);
    for (int i=0; i<rowLabels.size(); i++) {
        outputRowLabel(rowLabels[i]);
        for (int j=0; j<colLabels.size()-1; j++) {
            outputData(timingData[i][j], precision);
        }
        std::cout << std::endl;
        outputDivider(colLabels.size()*17);
    }
}
// Ouput column labels
void outputColLabels(std::vector<std::string> colLabels) {
    for (int i=0; i<colLabels.size(); i++) {
        std::cout << std::left <<"| " << std::setw(15) << colLabels[i];
    }
    std::cout << std::endl;
    outputDivider(colLabels.size()*17);

}

// Ouput divider line
void outputDivider(int size) {
    for (int i=0; i<size; i++) {
        std::cout << '-';
    }
    std::cout << std::endl;
}

// Ouput row label
void outputRowLabel(std::string label) {
    std::cout << std::left << "| " << std::setw(15) << label;
}

// Output data set to precision p
void outputData(double data, int p) {
    std:: cout << std::left <<"| " << std::setw(15) << std::setprecision(p) 
    << data;
}


