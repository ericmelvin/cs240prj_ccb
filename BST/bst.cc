#include "bst.hh"

//Insert - Determines where the new node for an int will be inserted in the 
//         binary search tree
void Insert(nodePtr newNode)
{
	nodePtr currentNode;
	bool found;

	//Initialize false
	found = false;

	//Start from the root of the tree
	currentNode = root;

	//Determine the location of the insertion based on root
	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		//Determine the type of insertion based on isAlpha
		if (isAlpha)
		{
			//While not at the end of list
			while (!found)
			{
				//Determine the direction of the tree based on the node value
				if (newNode->data.letter < currentNode->data.letter)
				{
					//Determine to insert a node based on the left ptr
					if (currentNode->left == NULL)
					{
						//Assign current node a value
						currentNode->left = newNode;

						//Assign found a value
						found = true;
					}
					else
					{
						currentNode = currentNode->left;
					}

				}
				else
				{
					//Determine to insert a node based on the right ptr
					if (currentNode->right == NULL)
					{
						//Assign current node a value
						currentNode->right = newNode;

						//Assign found a value
						found = true;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}
		}
		else
		{
			//While not at the end of list
			while (!found)
			{
				//Determine the direction of the tree based on the node value
				if (newNode->data.count < currentNode->data.count)
				{
					//Determine to insert a node based on the left ptr
					if (currentNode->left == NULL)
					{
						//Assign current node a value
						currentNode->left = newNode;

						//Assign found a value
						found = true;
					}
					else
					{
						currentNode = currentNode->left;
					}

				}
				else
				{
					//Determine to insert a node based on the right ptr
					if (currentNode->right == NULL)
					{
						//Assign current node a value
						currentNode->right = newNode;

						//Assign found a value
						found = true;
					}
					else
					{
						currentNode = currentNode->right;
					}
				}
			}
		}
	}
}

//DeleteLeafNode - Delete a leaf node from the tree
void DeleteLeafNode(nodePtr & currentPtr, nodePtr & parentPtr)
{
	//Determine the node location based on parentPtr
	if (parentPtr != NULL)
	{
		//Determine the parent's child based on the currentPtr
		if (parentPtr->left == currentPtr)
		{
			//Assign parent left ptr a value
			parentPtr->left = NULL;

			//Delete currentPtr
			delete currentPtr;
		}
		else
		{
			//Assign parent right ptr a value
			parentPtr->right = NULL;

			//Delete currentPtr
			delete currentPtr;
		}
	}
	else
	{
		//Assign root a value
		root = NULL;

		//Delete currentPtr
		delete currentPtr;
	}
}

//DeleteNodeLeftChildOnly - Delete a node with a left child from the tree
void DeleteNodeLeftChildOnly(nodePtr & currentPtr, nodePtr & parentPtr)
{
	//Determine the node location based on parentPtr
	if (parentPtr != NULL)
	{
		//Determine the parent's child based on the currentPtr
		if (parentPtr->left == currentPtr)
		{
			//Assign parent left ptr a value
			parentPtr->left = currentPtr->left;

			//Delete currentPtr
			delete currentPtr;
		}
		else
		{
			//Assign parent right ptr a value
			parentPtr->right = currentPtr->left;

			//Delete currentPtr
			delete currentPtr;
		}
	}
	else
	{
		//Assign root a value
		root = root->left;
	}
}

//DeleteNodeRightChildOnly - Delete a node with a right child from the tree
void DeleteNodeRightChildOnly(nodePtr & currentPtr, nodePtr & parentPtr)
{
	//Determine the node location based on parentPtr
	if (parentPtr != NULL)
	{
		//Determine the parent's child based on the currentPtr
		if (parentPtr->left == currentPtr)
		{
			//Assign parent left ptr a value
			parentPtr->left = currentPtr->right;

			//Delete currentPtr
			delete currentPtr;
		}
		else
		{
			//Assign parent right ptr a value
			parentPtr->right = currentPtr->right;

			//Delete currentPtr
			delete currentPtr;
		}
	}
	else
	{
		//Assign root a value
		root = root->right;
	}
}

//DeleteNodeWithTwoChildren - Delete a node with two children from the tree
void DeleteNodeWithTwoChildren(nodePtr & currentPtr, nodePtr & parentPtr)
{
	nodePtr dNode;

	//Assign dNode a value
	dNode = currentPtr;

	//Assign current ptr a value
	currentPtr = currentPtr->left;

	//Determine parentPtr value based on currentPtr
	if (currentPtr->right == NULL)
	{
		parentPtr = dNode;
	}

	//While not at the end of the list
	while (currentPtr->right != NULL)
	{
		//Assign parentPtr and currentPtr each a value
		parentPtr = currentPtr;
		currentPtr = currentPtr->right;
	}

	//Assign a value for root
	dNode->data.count = currentPtr->data.count;
	dNode->data.letter = currentPtr->data.letter;

	Delete(currentPtr, parentPtr);

}

//Delete - Call one of four delete methods based on the node type
void Delete(nodePtr & currentPtr, nodePtr & parentPtr)
{
	//Determine the delete method based on the currentPtr
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

//CreateTree - Set the root to NULL and isAlpha to true
void CreateTree(void)
{
	root = NULL;
	isAlpha = true;
}

//GetANode - Store a letter and the count in a node pointer and returns the pointer
nodePtr GetANode(char aLetter, int letterCount)
{
	//Create a node, set ptr to address of this node
	nodePtr aNode = new node;

	aNode->data.count = letterCount;
	aNode->data.letter = aLetter;

	aNode->left = NULL;
	aNode->right = NULL;

	return aNode;
}

//BuildTree - Create a binary search tree in numberic order using a passed in tree
void BuildCountTree(nodePtr parentPtr)
{
	//Assign isAlpha a value
	isAlpha = false;

	//Determine the to insert based on parentPtr
	if (parentPtr != NULL)
	{
		Insert(GetANode(parentPtr->data.letter, parentPtr->data.count));
		BuildCountTree(parentPtr->left);
		BuildCountTree(parentPtr->right);
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
void Inorder(ofstream & fout, nodePtr currentPtr)
{
	//Determine to output based on the currentPtr
	if (currentPtr != NULL)
	{
		Inorder(fout, currentPtr->left);

		//Output the current letter and count to the ouput file
		fout << setw(20) << currentPtr->data.letter
			<< setw(20) << currentPtr->data.count << endl;

		Inorder(fout, currentPtr->right);
	}
}

//Preorder - Traverse the binary tree and output the data preorder
void Preorder(ofstream & fout, nodePtr currentPtr)
{
	//Determine to output based on the currentPtr
	if (currentPtr != NULL)
	{
		//Output the current letter and count to the output file
		fout << setw(20) << currentPtr->data.letter
			<< setw(20) << currentPtr->data.count << endl;

		Inorder(fout, currentPtr->left);
		Inorder(fout, currentPtr->right);
	}
}

//Postorder - Traverse the binary tree and output the data postorder
void Postorder(ofstream & fout, nodePtr currentPtr)
{
	//Determine to output based on the currentPtr
	if (currentPtr != NULL)
	{
		Inorder(fout, currentPtr->left);
		Inorder(fout, currentPtr->right);

		//Output the current letter and count to the output file
		fout << setw(20) << currentPtr->data.letter
			<< setw(20) << currentPtr->data.count << endl;
	}
}

//Updatetree - Searching for the letter passed into the method and updates the count
void UpdateTree(char aLetter, nodePtr currentPtr)
{
	//Determine the letter position based on the currentPtr
	if (currentPtr->data.letter > aLetter)
	{
		UpdateTree(aLetter, currentPtr->left);
	}
	else if (currentPtr->data.letter < aLetter)
	{
		UpdateTree(aLetter, currentPtr->right);
	}
	else if (currentPtr->data.letter == aLetter)
	{
		//Increment currentPtr count
		currentPtr->data.count++;
	}
}

//FindMax - Search a binary tree and find the largest count
int FindLargestCount(void)
{
	int largest;
	nodePtr ptr;

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
	nodePtr & currentPtr, nodePtr & parentPtr)
{
	//Initialize currentPtr, parentPtr and found
	currentPtr = root;
	parentPtr = NULL;
	found = false;

	//Determine the type of search based on isAlpha
	if (isAlpha)
	{
		//While not at the end of list or found is false
		while (currentPtr != NULL && !found)
		{
			//Determine the found value based on the node's letter
			if (searchNode.letter == currentPtr->data.letter)
			{
				//Assign found a value
				found = true;
			}
			else if (searchNode.letter < currentPtr->data.letter)
			{
				//Assign current ptr to parent
				parentPtr = currentPtr;

				//Move to the left of the list
				currentPtr = currentPtr->left;
			}
			else
			{
				//Assign current ptr to parent
				parentPtr = currentPtr;

				//Move to the right of the list
				currentPtr = currentPtr->right;
			}
		}
	}
	else
	{
		//While not at the end of list or found is false
		while (currentPtr != NULL && !found)
		{
			//Determine the found value based on the node's count
			if (searchNode.count == currentPtr->data.count)
			{
				//Assign found a value
				found = true;
			}
			else if (searchNode.letter < currentPtr->data.letter)
			{
				//Assign current ptr to parent
				parentPtr = currentPtr;

				//Move to the left of the list
				currentPtr = currentPtr->left;
			}
			else
			{
				//Assign current ptr to parent
				parentPtr = currentPtr;

				//Move to the right of the list
				currentPtr = currentPtr->right;
			}
		}
	}
}

//DeleteNode - Delete the passed in node if found and output the result
void DeleteNode(nodeStructType searchNode, bool & found)
{
	nodePtr current;
	nodePtr parent;

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

