// Program input and output
#include <iomanip>
#include <iostream>
#include <vector>
#include "io.hh"
#include "graph.hh"


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
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(
                   clock.time_since_epoch()).count() << std::endl;
    return std::chrono::duration_cast<std::chrono::microseconds>(
                   clock.time_since_epoch()).count();
}

// Ouput table functions -------------------------------------------------------
// Ouput full table
void outputTable(std::vector<std::vector<int>> timingData, std::vector<std::string> colLabels, std::vector<std::string> rowLabels) {
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


