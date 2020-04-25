#ifndef REDBLACKTREE_HH
#define REDBLACKTREE_HH

#include <iostream>
#include <algorithm>

//Define node struct
struct node
{
	int data;
	char color;
	node* parent;
	node* left;
	node* right;
	/* constructor for node, default color RED */
	Node(int num)
		:data(num), color('r'), parent(nullptr), left(nullptr), child(nullptr)
		{}
};

class RBTree
{
private:
	node* root;

	//void Insert(int data);
	/* Rebalance the tree whenever we insert a new node n */
	void Rebalance(node *root, node *n);

	node * BSTInsert(node *root, node *n);

	void RightRotate(node *n);

	void LeftRotate(node *n);

	void DeleteLeafNode(node* currentPtr, node* parentPtr);

	void DeleteNodeLeftChildOnly(node* currentPtr, node* parentPtr);

	void DeleteNodeRightChildOnly(node* currentPtr, node* parentPtr);

	void DeleteNodeWithTwoChildren(node* currentPtr, node* parentPtr);

	void Delete(node* currentPtr, node* parentPtr);

public:
	treeClassType() { CreateTree(); };

	void CreateTree(void);

	void Insert(node *root, int data);

	bool IsEmpty(void) { return root == NULL; };

	node* GetRoot(void) { return root; };

	node* CreateNode(char aLetter, int letterCount);

	void BuildTree();

	void FindMax();

	void FindMin();

	void Search();

	void Remove();

	void DestroyTree(void);

	//Destructor
	~redBlackTree() { DestroyTree(); };
};

#endif //!REDBLACKTREE_HH
