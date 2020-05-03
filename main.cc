#include <iomanip>
#include <iostream>
#include <vector>
#include "bst.hh"
#include "RBT.hh"
#include "io.hh"
#include "matplotlibcpp.h"
#include "graph.hh"
#include <vector>

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
	std::vector<int> timingDataBST;
	std::vector<int> timingDataRBT;

	int start = 0;
	int end = 0;

    // output table labels
    std::vector<std::string> h = {"Data Structure", "Size", "buildTree()", "findMin()", "findMax()", "search()"};
    std::vector<std::string> rowLabels = {"BST", "RBT"};

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
	start = getCurrentTime();
	bst.BuildTree(infile);
	end = getCurrentTime();
	timingDataBST.push_back(end-start);

	//Find max
	start = getCurrentTime();
	std::cout << "Max: " << bst.FindMax() << std::endl;
	end = getCurrentTime();
	timingDataBST.push_back(end-start);

	//Find min
	start = getCurrentTime();
	std::cout << "Min: " << bst.FindMin() << std::endl;
	end = getCurrentTime();
	timingDataBST.push_back(end-start);

	//Search tree
	start = getCurrentTime();
	std::cout << "Search: " << std::endl;
	bst.Search(17200);
	end = getCurrentTime();
	timingDataBST.push_back(end-start);

	//------------------------------------------
	RBTree rbt;
	int x = 0;
	//time
	start = getCurrentTime();
	while(infile >> x){
		rbt.insert(x);
	}
	end = getCurrentTime();
	timingDataRBT.push_back(end-start);

	//time 
	start = getCurrentTime();
	//std::cout << "Max: " << rbt.findMax() << std::endl;
	end = getCurrentTime();
	timingDataRBT.push_back(end-start);

	//time
	start = getCurrentTime();
	//std::cout << "Min: " << rbt.findMin() << std::endl;
	end = getCurrentTime();
	timingDataRBT.push_back(end-start);

	//time
	start = getCurrentTime();
	//NodeRBT *n = rbt.search(1);
	end = getCurrentTime();
	timingDataRBT.push_back(end-start);
	std::cout << "Search for [num] --> ";
	//n->printNodeRBT();

	for (int i =0; i<timingDataBST.size(); i++) {
		std::cout << timingDataBST[i] << std::endl;
	}
	std::vector<int> test1, test2;
    for(int i=0; i<4; i++) {
        test1.push_back(i);
        test2.push_back(i*2);
    }
	makeGraph(test1, test2);
	
	std::vector<std::vector<int>> tableData;
	tableData.push_back(timingDataRBT);
	tableData.push_back(timingDataBST);
	outputTable(tableData, h, rowLabels);
	return 0;
}
