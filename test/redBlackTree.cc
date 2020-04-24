#include "redBlackTree.hh"


node* RBTree::BSTInsert(node *root, node* n){
	if(root == nullptr) return n;
	if(n->data < root->data){
		root->left = BSTInsert(root->left, n);
		root->left->parent = root;
	}else if(n->data > root->data){
		root->right = BSTInsert(root->right, n);
		root->right->parent = root;
	}
	/* set parent pointer of inserted node and return original root node */
	return root;
}

//-------------------------------------------------------------------------------------------------

/* Insert an integer into a tree 
 *	Use the data to create a node
 *	All nodes must be inserted with the color red and changed 
 *	accordingly to maintain balance
 * */



void redBlackTree::Insert(int data)
{
	node* n = new Node(data);
	/* Regular BST insertion */
	root = BSTInsert(root, n);
	
	/* rebalance the tree with the node we just inserted 
	 * Root node should always be black	
	 * */
	Rebalance(root, n);
}

void RBTree::Rebalance(node *root, node* n){
	node *temp_parent = nullptr;
	node *temp_grandparent = nullptr;
	while((n != root) && (n->color != 'b') && (n->parent->color == 'r')){
	
	}

}

//-------------------------------------------------------------------------------------------------
void redBlackTree::DeleteLeafNode(node* currentPtr, node* parentPtr)
{
	if (parentPtr != NULL)
	{
		if (parentPtr->left == currentPtr)
		{
			parentPtr->left = NULL;
			delete currentPtr;
		}
		else
		{
			parentPtr->right = NULL;
			delete currentPtr;
		}
	}
	else
	{
		root = NULL;
		delete currentPtr;
	}
}

//-------------------------------------------------------------------------------------------------
void redBlackTree::DeleteNodeLeftChildOnly(node* currentPtr, node* parentPtr)
{
	if (parentPtr != NULL)
	{
		if (parentPtr->left == currentPtr)
		{
			parentPtr->left = currentPtr->left;
			delete currentPtr;
		}
		else
		{
			parentPtr->right = currentPtr->left;
			delete currentPtr;
		}
	}
	else
	{
		root = root->left;
	}
}

//-------------------------------------------------------------------------------------------------
void redBlackTree::DeleteNodeRightChildOnly(node* currentPtr, node* parentPtr)
{
	if (parentPtr != NULL)
	{
		if (parentPtr->left == currentPtr)
		{
			parentPtr->left = currentPtr->right;
			delete currentPtr;
		}
		else
		{
			parentPtr->right = currentPtr->right;
			delete currentPtr;
		}
	}
	else
	{
		root = root->right;
	}
}

//-------------------------------------------------------------------------------------------------
void redBlackTree::DeleteNodeWithTwoChildren(node* currentPtr, node* parentPtr)
{
	nodePtr dNode;

	dNode = currentPtr;

	currentPtr = currentPtr->left;

	if (currentPtr->right == NULL)
	{
		parentPtr = dNode;
	}

	while (currentPtr->right != NULL)
	{
		parentPtr = currentPtr;
		currentPtr = currentPtr->right;
	}

	dNode->data.count = currentPtr->data.count;
	dNode->data.letter = currentPtr->data.letter;

	Delete(currentPtr, parentPtr);

}

//-------------------------------------------------------------------------------------------------
void redBlackTree::Delete(node* currentPtr, node* parentPtr)
{
	if (currentPtr->left == NULL && currentPtr->right == NULL)
	{
		DeleteLeafNode(currentPtr, parentPtr);
	}
	else if (currentPtr->left != NULL && currentPtr->right == NULL)
	{
		DeleteNodeLeftChildOnly(currentPtr, parentPtr);
	}
	else if (currentPtr->left == NULL && currentPtr->right != NULL)
	{
		DeleteNodeRightChildOnly(currentPtr, parentPtr);
	}
	else
	{
		DeleteNodeWithTwoChildren(currentPtr, parentPtr);
	}
}

//-------------------------------------------------------------------------------------------------
void redBlackTree::CreateTree(void)
{
	root = NULL;
}

//-------------------------------------------------------------------------------------------------
node* redBlackTree::CreatNode(int dta)
{
	node* aNode = new node;

	aNode->color = red;
	aNode->data = dta;

	aNode->left = NULL;
	aNode->right = NULL;
	aNode->parent = NULL;

	return aNode;
}

//-------------------------------------------------------------------------------------------------
node* redBlackTree::DestroyTree(void)
{
	int count = 1;
	bool found = false;

	while (root != NULL)
	{
		//For testing, delete when using high amount of data
		cout << "Destroy #" << count << endl
			<< "Deleted Node: " << root->data
			<< endl;

		DeleteNode(root->data, found);

		count++;
	}

	cout << endl;
}
