#include <iostream>
#include <fstream>
#include <string>

#ifndef BST_HH
#define BST_HH

//Define node structure
struct node
{
	int data;
	node* left;
	node* right;

	Node(int num)
		:data(num), left(nullptr), child(nullptr)
	{}
};

class BST
{
private:
	nodePtr root;

	void Insert(nodePtr newNode);
	void DeleteLeafNode(nodePtr& currentPtr, nodePtr& parentPtr);
	void DeleteNodeLeftChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
	void DeleteNodeRightChildOnly(nodePtr& currentPtr, nodePtr& parentPtr);
	void DeleteNodeWithTwoChildren(nodePtr& currentPtr, nodePtr& parentPtr);
	void Delete(nodePtr& currentPtr, nodePtr& parentPtr);

public:
	//Constructor
	BST() { CreateTree(); };

	void CreateTree(void);

	bool IsEmpty(void) { return root == NULL; };

	nodePtr GetRoot(void) { return root; };

	nodePtr GetANode(char aLetter, int letterCount);

	void BuildTree(nodePtr parentPtr);

	void ProcessText(ifstream& fin);

	void Inorder(ofstream& fout, nodePtr currentPtr);

	void Preorder(ofstream& fout, nodePtr currentPtr);

	void Postorder(ofstream& fout, nodePtr currentPtr);

	void UpdateTree(char aLetter, nodePtr currentPtr);

	int FindMax(void);

	int FindMin(void);

	void SearchTree(nodeStructType searchNode, bool& found,
		nodePtr& currentPtr, nodePtr& parentPtr);

	void DeleteNode(nodeStructType searchNode, bool& found);

	void DestroyTree(void);

	void Print(ofstream& fout, string traversalType, string treeType, string taskType);

	//Destructor
	~BST() { DestroyTree(); };

};

#endif // !BST_HH
