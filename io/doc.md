CS240 Group Documentation
Collaborators
Cindy Guo
Cat Tran
Barrett Sweet
Project Description
Build an application to compare the implementation of binary search trees and red black trees.

Requirements
The program will be run as follows: ./main FILE_PATH The input file, FILE_PATH, containing integers will be fed to the main program and the program will build a red-black tree and a binary tree from the input. The program will then output the time needed for the red-black tree and binary tree to execute each of the following commands: building the tree, execute a search for a random number, remove a random number, and find the maximum and minimum node of the tree. Upon successful execution, the time required for the red-black tree and the binary tree to execute each command will be displayed in seconds.

Properties of Red-Black Trees
Every node contains a color (red or black)
The root node is black
If a node is red, then its parent and children (if any) must be black
Desired Output
n = seconds to run function

findMin()	findMax()	findK()	buildTree()
BST	n	n	n	n
RBT	n	n	n	n
Classes
BST Methods
insert
Input: int value to insert
Output: none
findMin
Input: none
Output: integer min_value
findMax
Input: none
Output: integer max_value
findK
Input: an arbitrary value k to search for
Ouput: boolean found_k
RBT Methods
insert
Input: int value to insert
Output: none
findMin
Input: none
Output: integer min_value
findMax
Input: none
Output: integer max_value
findK
Input: an arbitrary value k to search for
Ouput: boolean found_k
Other Methods
File: io.cc
inputFile
Input: file of integers
Output: None
outputTable
Purpose: output timing data for different data structures and methods run on them
Input: Timing data as a 2D array
Input: column labels
Input: row labels
Output: Table formatted with timing data
std::vector genInputNumbers(int length, int max);
Helper functions
void outputColLabels(std::vectorstd::string colLabels);
void outputDivider(int size);
void outputRowLabel(std::string label);
void outputData(double data, int p);
Helper functions
void outputColLabels(std::vectorstd::string colLabels);
void outputDivider(int size);
void outputRowLabel(std::string label);
void outputData(double data, int p);
getCurrentTime
Input: none
Output: number of milliseconds since epoch time
Generate input numbers
Input: integer n: number of ints to generate
Input: int n: number of ints to generate
Output: An array or file containing ints
Parse command line args
Input: argv
Output: Control flow
File: graph.cc
Dependencies:
matplotlibcpp.h
Python 2.7
Numpy
makeGraph
Purpose: Create a graph comparing timing data from different data structures and methods run on them.
Input: Will accept timing data in future update
Output: A graph. Returns void.
Helper functions
labelSpacing
Input: int numLabels: The number of x axis labels
References:
https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/