#include <iostream>
#include <fstream>
#include <string>

#ifndef BST_HH
#define BST_HH

//Define Node structure
struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int num)
		:data(num), left(nullptr), right(nullptr)
	{}
};

class BST
{
private:
	Node* root;
	int dups;

	void Insert(Node* n);

	void DeleteLeafNode(Node*& curr, Node*& parent);

	void DeleteNodeLeftChildOnly(Node*& curr, Node*& parent);

	void DeleteNodeRightChildOnly(Node*& curr, Node*& parent);

	void DeleteNodeWithTwoChildren(Node*& curr, Node*& parent);

	void Delete(Node*& curr, Node*& parent);
public:
	//Constructor
	BST() { CreateTree(); };

	void CreateTree(void);

	bool IsEmpty(void) { return root == NULL; };

	Node* GetRoot(void) { return root; };

	Node* CreateNode(int num);

	//------------------------WORKING-----------------------------

	void BuildTree(std::ifstream & fin);

	int FindMax(void);

	int FindMin(void);

	bool Search(int num, Node* & curr, Node* & parent);

	bool Search(int num);

	void DeleteNode(int num);

	void DestroyTree(void);

	//Destructor
	~BST() { DestroyTree(); };

};

#endif // !BST_HH
