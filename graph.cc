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
void makeGraph(std::vector<std::string> labels, std::vector<int> timingDataBST, std::vector<int> timingDataRBT) {

    std::vector<int> spacing = labelSpacing(labels.size());
    timingDataBST.erase(timingDataBST.begin());
    timingDataRBT.erase(timingDataRBT.begin());
    plt::xticks(spacing, labels);

    // Bar positions
    std::vector<int> a = {0, 2, 4};
    std::vector<int> b = {1, 3, 5};

    std::vector<int> x,y;
    plt::named_plot("Binary Search Tree", x, y);
    plt::named_plot("Red Black Tree", x, y);
    plt::ylabel("Time (Microseconds)");
    plt::xlabel("Function");
    plt::bar(a, timingDataBST);
    plt::bar(b, timingDataRBT);
    
    plt::legend();
    plt::show();
    
}

