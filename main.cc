#include <iomanip>
#include <iostream>
#include <vector>
#include "bst.hh"
#include "RBT.hh"
#include "io.hh"
#include "matplotlibcpp.h"
#include "graph.hh"
//Test if input valid
void InputTest(std::ifstream &infile, char ** argv)
{
	int num;

	while (infile.good()) {
		infile >> num;
	}
	if (!infile.eof()) {
		std::cerr << "Cannot read " << argv[1]
			<< ": No such input file or directory" << std::endl;
		std::exit(1);
	}

	infile.clear();
	infile.seekg(0, infile.beg);
}

void TestBST(std::ifstream &infile, BST &bst)
{
	//Build tree
	bst.BuildTree(infile);

	//Find max
	std::cout << "Max: " << bst.FindMax() << std::endl;

	//Find min
	std::cout << "Min: " << bst.FindMin() << std::endl;

	//Search tree
	bst.Search(17200);
	bst.Search(6941);
	bst.Search(321);
}

int main(int argc, char *argv[]){

	// IO Testing --------------------------------------------------------------
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
	// -------------------------------------------------------------------------
	//Test if input is correct
	if (argc < 3) {
		std::cerr << "usage: " << argv[0]
			<< " INPUT_FILE FUNCTIONS " << std::endl
			<< "FUNCTIONS: - SEARCH n" << std::endl
			<< "           - INSERT n" << std::endl
			<< "           - REMOVE n" << std::endl
			<< "           - FINDMIN" << std::endl
			<< "           - FINDMAX" << std::endl
		    << "           - FINDMINMAX" << std::endl;
		std::exit(1);
	}

	// Open file for reading
	std::ifstream infile(argv[1]);

	//Test if file exist
	InputTest(infile, argv);

	BST bst;
	Node *root = bst.GetRoot();

	//Time these functions
	//------------------BST---------------------
	//Build tree
	bst.BuildTree(infile);

	//Find max
	std::cout << "Max: " << bst.FindMax() << std::endl;

	//Find min
	std::cout << "Min: " << bst.FindMin() << std::endl;

	//Search tree
	std::cout << "Search: " << std::endl;
	bst.Search(17200);
	bst.Search(6941);
	bst.Search(321);
	//------------------------------------------
	return 0;
}
