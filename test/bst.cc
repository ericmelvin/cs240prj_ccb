#include "bst.hh"

//Insert - Determines where the new node for an int will be inserted in the 
//         binary search tree
void Insert(node* n)
{
	node* curr = root;
	bool found = false;

	if (root == NULL)
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
				if (curr->left == NULL)
				{
					curr->left = n;
					found = true;
				}
				else
				{
					curr = curr->left;
				}

			}//Right
			else
			{
				if (curr->right == NULL)
				{
					curr->right = n;
					found = true;
				}
				else
				{
					curr = curr->right;
				}
			}
		}
	}
}

//DeleteLeafNode - Delete a leaf node from the tree
void DeleteLeafNode(node* & curr, node* & parent)
{
	if (parent != NULL)
	{
		//Determine the parent's child
		if (parent->left == curr)
		{
			parent->left = nullptr;
			delete curr;
		}
		else
		{
			parent->right = nullptr;
			delete curr;
		}
	}
	else
	{
		root = nullptr;
		delete curr;
	}
}

//DeleteNodeLeftChildOnly - Delete a node with a left child from the tree
void DeleteNodeLeftChildOnly(node* & curr, node* & parent)
{
	if (parent != NULL)
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

//DeleteNodeRightChildOnly - Delete a node with a right child from the tree
void DeleteNodeRightChildOnly(node* & curr, node* & parent)
{
	if (parent != NULL)
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

//DeleteNodeWithTwoChildren - Delete a node with two children from the tree
void DeleteNodeWithTwoChildren(node* & curr, node* & parent)
{
	node* dNode;
	dNode = curr;
	curr = curr->left;

	if (curr->right == NULL)
	{
		parent = dNode;
	}

	//While not at the end of the list
	while (curr->right != NULL)
	{
		//Assign parent and curr each a value
		parent = curr;
		curr = curr->right;
	}

	//Assign a value for root
	dNode->data = curr->data;
	Delete(curr, parent);
}

//Delete - Call one of four delete methods based on the node type
void Delete(node* & curr, node* & parent)
{
	//Determine the delete method based on the curr
	if (curr->left == NULL && curr->right == NULL)
	{
		DeleteLeafNode(curr, parent);
	}
	else if (curr->left != NULL && curr->right == NULL)
	{
		DeleteNodeLeftChildOnly(curr, parent);
	}
	else if (curr->left == NULL && curr->right != NULL)
	{
		DeleteNodeRightChildOnly(curr, parent);
	}
	else
	{
		DeleteNodeWithTwoChildren(curr, parent);
	}
}

//CreateTree - Set the root to NULL and isAlpha to true
void CreateTree(void)
{
	root = NULL;
}

//CreateNode - Create a node pointer with num and returns the pointer
node* CreateNode(int num)
{
	node* aNode = new node;

	aNode->data = num;

	aNode->left = NULL;
	aNode->right = NULL;

	return aNode;
}

//-----------------------------------------WORKING-----------------------------------------------

//BuildTree - Create a binary search tree in numberic order using a passed in tree
void BuildCountTree(node* parent)
{
	//Assign isAlpha a value
	isAlpha = false;

	//Determine the to insert based on parent
	if (parent != NULL)
	{
		Insert(GetANode(parent->data.letter, parent->data.count));
		BuildCountTree(parent->left);
		BuildCountTree(parent->right);
	}
}

//ProcessText - Read the text file and update the tree with all the letters
void ProcessText(ifstream & fin)
{
	char letter;

	//Input the letter from the input file
	fin >> letter;

	//While there are data in the file
	while (fin)
	{
		//Lowercase the letter
		letter = tolower(letter);

		//Determine to update tree based on the input character
		if (isalpha(letter))
		{
			UpdateTree(letter, root);
		}

		//Input the letter from the input file
		fin >> letter;
	}
}

//Inorder - Traverse the binary tree and output the data inorder
void Inorder(ofstream & fout, node* curr)
{
	//Determine to output based on the curr
	if (curr != NULL)
	{
		Inorder(fout, curr->left);

		//Output the current letter and count to the ouput file
		fout << setw(20) << curr->data.letter
			<< setw(20) << curr->data.count << endl;

		Inorder(fout, curr->right);
	}
}

//Preorder - Traverse the binary tree and output the data preorder
void Preorder(ofstream & fout, node* curr)
{
	//Determine to output based on the curr
	if (curr != NULL)
	{
		//Output the current letter and count to the output file
		fout << setw(20) << curr->data.letter
			<< setw(20) << curr->data.count << endl;

		Inorder(fout, curr->left);
		Inorder(fout, curr->right);
	}
}

//Postorder - Traverse the binary tree and output the data postorder
void Postorder(ofstream & fout, node* curr)
{
	//Determine to output based on the curr
	if (curr != NULL)
	{
		Inorder(fout, curr->left);
		Inorder(fout, curr->right);

		//Output the current letter and count to the output file
		fout << setw(20) << curr->data.letter
			<< setw(20) << curr->data.count << endl;
	}
}

//Updatetree - Searching for the letter passed into the method and updates the count
void UpdateTree(char aLetter, node* curr)
{
	//Determine the letter position based on the curr
	if (curr->data.letter > aLetter)
	{
		UpdateTree(aLetter, curr->left);
	}
	else if (curr->data.letter < aLetter)
	{
		UpdateTree(aLetter, curr->right);
	}
	else if (curr->data.letter == aLetter)
	{
		//Increment curr count
		curr->data.count++;
	}
}

//FindMax - Search a binary tree and find the largest count
int FindLargestCount(void)
{
	int largest;
	node* ptr;

	//Initialize prt and largest
	ptr = root;
	largest = 0;

	//While not at the end of list
	while (ptr != NULL)
	{
		//Assign largest a value
		largest = ptr->data.count;

		//Move the pointer along
		ptr = ptr->right;
	}

	return largest;
}

//SearchTree - Search the tree for a node with the right data, return that node and the parent
void SearchTree(nodeStructType searchNode, bool & found,
	node* & curr, node* & parent)
{
	//Initialize curr, parent and found
	curr = root;
	parent = NULL;
	found = false;

	//Determine the type of search based on isAlpha
	if (isAlpha)
	{
		//While not at the end of list or found is false
		while (curr != NULL && !found)
		{
			//Determine the found value based on the node's letter
			if (searchNode.letter == curr->data.letter)
			{
				//Assign found a value
				found = true;
			}
			else if (searchNode.letter < curr->data.letter)
			{
				//Assign current ptr to parent
				parent = curr;

				//Move to the left of the list
				curr = curr->left;
			}
			else
			{
				//Assign current ptr to parent
				parent = curr;

				//Move to the right of the list
				curr = curr->right;
			}
		}
	}
	else
	{
		//While not at the end of list or found is false
		while (curr != NULL && !found)
		{
			//Determine the found value based on the node's count
			if (searchNode.count == curr->data.count)
			{
				//Assign found a value
				found = true;
			}
			else if (searchNode.letter < curr->data.letter)
			{
				//Assign current ptr to parent
				parent = curr;

				//Move to the left of the list
				curr = curr->left;
			}
			else
			{
				//Assign current ptr to parent
				parent = curr;

				//Move to the right of the list
				curr = curr->right;
			}
		}
	}
}

//DeleteNode - Delete the passed in node if found and output the result
void DeleteNode(nodeStructType searchNode, bool & found)
{
	node* current;
	node* parent;

	SearchTree(searchNode, found, current, parent);

	//Determine the output based on found
	if (found)
	{
		Delete(current, parent);
	}
}

//DestroyTree - Delete all nodes in the tree
void DestroyTree(void)
{
	int count;

	bool found;

	//Initialize count and found
	count = 1;
	found = false;

	//While root is not deleted
	while (root != NULL)
	{
		//Output deleted message to the screen
		cout << "Destroy #" << count << endl
			<< "Deleted Node - Letter: " << root->data.letter
			<< " Count: " << root->data.count << endl;

		DeleteNode(root->data, found);

		//Increment count
		count++;
	}

	//Output a blank line
	cout << endl;
}

//Print - Output a heading identifying which tree is being printed and the tree
void Print(ofstream & fout, string traversalType, string treeType, string taskType)
{
	PrintDivider(fout, '-', DIVIDER_WIDTH);

	//Output the print heading to the output file
	fout << "This is the " << treeType << " tree" << endl;
	fout << traversalType << " traversal of the tree" << endl;
	fout << "Task Performed: " << taskType << endl;

	PrintDivider(fout, '-', DIVIDER_WIDTH);

	//Output the print heading to the output file
	fout << setw(20) << "Letter" << setw(20) << "Count" << endl;

	PrintDivider(fout, '-', DIVIDER_WIDTH);

	//Determine the type of traverse base on traversal type
	if (traversalType == "Preorder")
	{
		Preorder(fout, root);
	}
	else if (traversalType == "Inorder")
	{
		Inorder(fout, root);
	}
	else
	{
		Postorder(fout, root);
	}

	PrintDivider(fout, '-', DIVIDER_WIDTH);

	//Output the sum of counts to the output file
	fout << "Sum of Counts: " << setw(25) << SumCounts(root) << endl;

	PrintDivider(fout, '-', DIVIDER_WIDTH);

	//Output a blank line to the output file
	fout << endl;
}

