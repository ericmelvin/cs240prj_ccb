#include "redBlackTree.h"

//-------------------------------------------------------------------------------------------------
void redBlackTree::Insert(node* newNode)
{
	node* currentNode = root;
	bool found = false;;

	if (root == NULL)
	{
		root = newNode;
	}
	else
	{

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
	isAlpha = true;
}

//-------------------------------------------------------------------------------------------------
node* redBlackTree::CreatNode(char clr, int dta)
{
	node* aNode = new node;

	aNode->color = clr;
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