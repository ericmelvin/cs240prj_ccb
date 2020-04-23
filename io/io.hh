#ifndef IO_HH_
#define IO_HH_
#include <chrono>

// Generate a vector of random numbers for input to structures
// Input length: length of vector
// Input max: maximum value in vector
std::vector<int> genInputNumbers(int length, int max);

unsigned long getCurrentTime();
void outputTable(std::vector<std::vector<double>> timingData, std::vector<std::string> colLabels, std::vector<std::string> rowLabels);
void outputColLabels(std::vector<std::string> header);
void outputDivider(int size);
void outputRowLabel(std::string label);
void outputData(double data, int p);
#endif // IO_HH_