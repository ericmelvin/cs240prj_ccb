# CS240 Group Documentation

## Collaborators
- Cindy Guo
- Cat Tran
- Barrett Sweet


## Project Description
Build an application to compare the implementation of binary search trees and red black trees.

## Requirements
This program aims to implement a self balancing binary tree in the form of a red-black tree and compare it to an implementation of a regular binary tree. 

The program will be run as follows:
.exe FILE_PATH [command] [num]

The input file, FILE_PATH, containing integers will be fed to the main program and the program will build a red-black tree and a binary tree from the input. The program will then output the time needed for the red-black tree and binary tree to execute [command] [num] where command is one of search, insert, remove, max or min. If command is max or min then [num] input will be omitted. Upon successful execution of the command, the time required for the red-black tree and the binary tree to execute the command will be displayed in seconds. 


## Desired Output
n = seconds to run function
||findMin()|findMax()|findK()|buildTree()|
|---|---|---|---|---|
|BST| n | n | n | n |
|RBT| n | n | n | n |


## Classes

### BST Methods

#### insert
- Input: int value to insert
- Output: none
#### findMin
- Input: none
- Output: integer min_value
#### findMax
- Input: none
- Output: integer max_value
#### findK
- Input: an arbitrary value k to search for
- Ouput: boolean found_k

### RBT Methods

#### insert
- Input: int value to insert
- Output: none
#### findMin
- Input: none
- Output: integer min_value
#### findMax
- Input: none
- Output: integer max_value
#### findK
- Input: an arbitrary value k to search for
- Ouput: boolean found_k


## Other Methods
### File: io.cc

#### inputFile
- Input: file of integers
- Output: None
#### outputTable
- Input: Timing data as a 2D array
- Input: column labels 
- Input: row labels
- Output: Table formatted with timing data
- std::vector<int> genInputNumbers(int length, int max);
  - ##### Helper functions
  - void outputColLabels(std::vector<std::string> colLabels);
  - void outputDivider(int size);
  - void outputRowLabel(std::string label);
  - void outputData(double data, int p);
#### getCurrentTime
- Input: none
- Output: number of milliseconds since epoch time
#### Generate input numbers
- Input: integer n: number of ints to generate
- Output: An array or file containing ints
#### Parse command line args
- Input: argv
- Output: Control flow
