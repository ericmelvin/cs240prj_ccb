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
        spacing.push_back(i*2);
    }
    return spacing;
}
void makeGraph(std::vector<int> timingDataBST, std::vector<int> timingDataRBT) {
    std::vector<std::string> labels = {"buildTree()", "findMin()", "findMax()", "search()"};

    std::vector<int> spacing = labelSpacing(labels.size());
    
    plt::xticks(spacing, labels);

    // Bar positions
    std::vector<int> a = {0, 2, 4, 6};
    std::vector<int> b = {1, 3, 5, 7};

    plt::bar(a, timingDataBST);
    plt::bar(b, timingDataRBT);
    
    plt::show();
    
}

