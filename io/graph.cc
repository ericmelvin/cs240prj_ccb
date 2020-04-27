#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include "matplotlibcpp.h"
#include "graph.hh"
namespace plt = matplotlibcpp;

std::vector<int> labelSpacing(int numLabels) { 
    std::vector<int> spacing;
    for (int i=0; i<numLabels; i++) {
        spacing.push_back(i);
    }
    return spacing;
}
void makeGraph() {
    std::vector<std::string> labels = {"findMin()", "findMax()", "findK()", "insert()"};

    std::vector<int> spacing = labelSpacing(labels.size());
    
    std::vector<int> test_data, test_data2;
    for (int i = 1; i < 5; i++) {
        test_data.push_back(i);
        test_data2.push_back(i+i);
    }
    plt::xticks(spacing, labels);
    std::vector<int> a = {0, 2, 4, 6};
    std::vector<int> b = {1, 3, 5, 7};
    plt::bar(a, test_data);
    plt::bar(b, test_data2);
    
    plt::show();
    
}

