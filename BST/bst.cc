#include "bst.hh"

//Insert - Determines where the new Node for an int will be inserted in the 
//         binary search tree
BST() { CreateTree(); };

void Insert(Node* n)
{
	Node* curr = root;
	bool found = false;

	if (root == nullptrptr)
	{
		root = n;
	}
	else
	{
		//While not at the end of list
		while (!found)
		{
			//Left
			if (n->data < curr->data)
			{
				if (curr->left == nullptrptr)
				{
					curr->left = n;
					found = true;
				}
				else
				{
					curr = curr->left;
				}

			}//Right
			else if (n->data > curr->data)
			{
				if (curr->right == nullptrptr)
				{
					curr->right = n;
					found = true;
				}
				else
				{
					curr = curr->right;
				}
			}//Equal
			else {
				dups++;
			}
		}
	}
}

//DeleteLeafNode - Delete a leaf Node from the tree
void DeleteLeafNode(Node* & curr, Node* & parent)
{
	if (parent != nullptrptr)
	{
		//Determine the parent's child
		if (parent->left == curr)
		{
			parent->left = nullptrptr;
			delete curr;
		}
		else
		{
			parent->right = nullptrptr;
			delete curr;
		}
	}
	else
	{
		root = nullptrptr;
		delete curr;
	}
}

//DeleteNodeLeftChildOnly - Delete a Node with a left child from the tree
void DeleteNodeLeftChildOnly(Node* & curr, Node* & parent)
{
	if (parent != nullptrptr)
	{
		if (parent->left == curr)
		{
			parent->left = curr->left;
			delete curr;
		}
		else
		{
			parent->right = curr->left;
			delete curr;
		}
	}
	else
	{
		root = root->left;
	}
}

//DeleteNodeRightChildOnly - Delete a Node with a right child from the tree
void DeleteNodeRightChildOnly(Node* & curr, Node* & parent)
{
	if (parent != nullptrptr)
	{
		if (parent->left == curr)
		{
			parent->left = curr->right;
			delete curr;
		}
		else
		{
			parent->right = curr->right;
			delete curr;
		}
	}
	else
	{
		root = root->right;
	}
}

//DeleteNodeWithTwoChildren - Delete a Node with two children from the tree
void DeleteNodeWithTwoChildren(Node* & curr, Node* & parent)
{
	Node* dNode;
	dNode = curr;
	curr = curr->left;

	if (curr->right == nullptrptr)
	{
		parent = dNode;
	}

	//While not at the end of the list
	while (curr->right != nullptrptr)
	{
		//Assign parent and curr each a value
		parent = curr;
		curr = curr->right;
	}

	//Assign a value for root
	dNode->data = curr->data;
	Delete(curr, parent);
}

//Delete - Call one of four delete methods based on the Node type
void Delete(Node* & curr, Node* & parent)
{
	//Determine the delete method based on the curr
	if (curr->left == nullptr && curr->right == nullptr)
	{
		DeleteLeafNode(curr, parent);
	}
	else if (curr->left != nullptr && curr->right == nullptr)
	{
		DeleteNodeLeftChildOnly(curr, parent);
	}
	else if (curr->left == nullptr && curr->right != nullptr)
	{
		DeleteNodeRightChildOnly(curr, parent);
	}
	else
	{
		DeleteNodeWithTwoChildren(curr, parent);
	}
}

//CreateTree - Set the root to nullptr and isAlpha to true
void CreateTree(void)
{
	root = nullptr;
}

//CreateNode - Create a Node pointer with num and returns the pointer
Node* CreateNode(int num)
{
	Node* aNode = new Node;

	aNode->data = num;

	aNode->left = nullptr;
	aNode->right = nullptr;

	return aNode;
}

//-----------------------------------------WORKING-----------------------------------------------

//BuildTree - Create a binary search tree in numberic order using a passed in tree
void BuildTree(std::ifstream & fin)
{
	int num;
	if (fin >> num)
	{
		Insert(CreateNode(num));
	}
}

//FindMax - Search a binary tree and find the largest data
int FindMax(void)
{
	int largest = 0;
	Node* ptr = root;

	//While not at the end of list
	while (ptr != nullptr)
	{
		//Assign largest a value
		largest = ptr->data;

		//Move the pointer along
		ptr = ptr->right;
	}

	return largest;
}

//FindMin - Search a binary tree and find the smallest data
int FindMin(void)
{
	int smallest = 0;
	Node* ptr = root;

	//While not at the end of list
	while (ptr != nullptr)
	{
		//Assign largest a value
		smallest = ptr->data;

		//Move the pointer along
		ptr = ptr->left;
	}

	return smallest;
}

//SearchTree - Search the tree for a Node with the right data, return that Node and the parent
void SearchTree(int num, bool & found, Node* & curr, Node* & parent)
{
	curr = root;
	parent = nullptr;
	found = false;

	//While not at the end of list or found is false
	while (curr != nullptr && !found)
	{
		if (num == curr->data)
		{
			found = true;
		}
		else if (num < curr->data)
		{
			parent = curr;
			curr = curr->left;
		}
		else
		{
			parent = curr;
			curr = curr->right;
		}
	}
}

//DeleteNode - Delete the passed in Node if found and output the result
void DeleteNode(int num)
{
	Node* current;
	Node* parent;
	bool found = false;

	SearchTree(searchNode, found, current, parent);

	if (found)
	{
		Delete(current, parent);
	}
}

//DestroyTree - Delete all Nodes in the tree
void DestroyTree(void)
{
	int count = 1;
	
	//While root is not deleted
	while (root != nullptr)
	{
		//Uncomment for debugging
		//cout << "Destroy #" << count << endl
		//	<< " Data: " << root->data.count << endl;

		DeleteNode(root->data);

		count++;
	}
}

~BST() { DestroyTree(); };