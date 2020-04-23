#ifndef REDBLACKTREE_HH
#define REDBLACKTREE_HH

//Define node struct
struct node
{
	int data;
	char color;
	node* parent;
	node* left;
	node* right;
};

class RBTree
{
private:
	node* root;

	void Insert(node* n);

	void RightRotate();

	void LeftRotate();

	void DeleteLeafNode(node* currentPtr, node* parentPtr);

	void DeleteNodeLeftChildOnly(node* currentPtr, node* parentPtr);

	void DeleteNodeRightChildOnly(node* currentPtr, node* parentPtr);

	void DeleteNodeWithTwoChildren(node* currentPtr, node* parentPtr);

	void Delete(node* currentPtr, node* parentPtr);

public:
	treeClassType() { CreateTree(); };

	void CreateTree(void);

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