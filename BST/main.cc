#include "bst.hh"

//Test if input valid
void InputTest(std::ifstream &infile, char ** argv)
{
	unsigned long long addr;
	string behavior;
	unsigned long long target;

	while (infile.good()) {
		infile >> std::hex >> addr >> behavior >> std::hex >> target;
	}
	if (!infile.eof()) {
		std::cerr << "Cannot read " << argv[1]
			<< ": No such input file or directory" << std::endl;
		std::exit(1);
	}

	ResetFile(infile);
}

int main(int argc, char *argv[]){
	//Test if input is correct
	if (argc < 3) {
		std::cerr << "usage: " << argv[0]
			<< " INPUT_TRACE OUTPUT_FILE..." << std::endl;
		std::exit(1);
	}

	// Open file for reading
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	//Test if file exist
	InputTest(infile, argv);

	BST bst;
	Node *root = bst.GetRoot();
	return 0;
}
