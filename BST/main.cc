#include "bst.hh"

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

int main(int argc, char *argv[]){
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

	bst.BuildTree(infile);

	std::cout << bst.FindMax() << std::endl;
	std::cout << bst.FindMin() << std::endl;
	bst.Search(5);
	bst.Search(30);

	return 0;
}
