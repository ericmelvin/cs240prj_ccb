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

	void Insert(node* n);
	void DeleteLeafNode(node*& curr, node*& parent);
	void DeleteNodeLeftChildOnly(node*& curr, node*& parent);
	void DeleteNodeRightChildOnly(node*& curr, node*& parent);
	void DeleteNodeWithTwoChildren(node*& curr, node*& parent);
	void Delete(node*& curr, node*& parent);
public:
	//Constructor
	BST() { CreateTree(); };

	void CreateTree(void);

	bool IsEmpty(void) { return root == NULL; };

	node* GetRoot(void) { return root; };

	node* CreateNode(int num);

	//------------------------WORKING-----------------------------

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
