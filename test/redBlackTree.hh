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

	bool leftChild(){ 
		return this == parent->left;
	}
	bool rightChild(){
		return this == parent->right;
	}
	
	node *uncle(){
		if(parent == nullptr || parent->parent == nullptr){
			return nullptr;
		}
		if(parent->leftChild()){
			return parent->parent->right;
		}else if(parent->rightChild()){
			return parent->parent->left;
		}
	}

	node *sibling(){
		if(parent == nullptr) return nullptr;
		if(leftChild) return parent->right;
		if(rightChild) return parent->left;
	}

	void siftDown(node *nparent){
		if(parent != nullptr){
			if(leftChild()){
				parent->left = nparent;
			}else{
				parent->right = nparent;
			}
		}
		nparent->parent = parent;
		parent = nparent;
	}


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
