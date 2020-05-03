#include <iostream>
#include <queue>

enum COLOR { RED, BLACK };

class NodeRBT {
public:
    int val;
    COLOR color;
    NodeRBT *left, *right, *parent;

    NodeRBT(int val) : val(val) {
        parent = left = right = nullptr;
        
        // NodeRBT is created during insertion
        // NodeRBT is red at insertion
        color = RED;
    }
	

    void printNodeRBT(){
    	std::cout << "Value: " << this->val << " Color: " << this->color << " Parent: " << 
		&parent << " Left Child: " << &left << " Right Child: " << &right << std::endl;
    }

    // returns pointer to uncle
    NodeRBT *uncle() {
        // If no parent or grandparent, then no uncle
        if (parent == nullptr || parent->parent == nullptr)
        return nullptr;

        if (parent->isOnLeft()){
		return parent->parent->right;
	} else{
		return parent->parent->left;
	}
    }

    // check if NodeRBT is left child of parent
    bool isOnLeft() { return this == parent->left; }

    // returns pointer to sibling
    NodeRBT *sibling() {
        // sibling null if no parent
        if (parent == nullptr)
        return nullptr;

        if (isOnLeft()) return parent->right;

        return parent->left;
    }

    // moves NodeRBT down and moves given NodeRBT in its place
    void moveDown(NodeRBT *nParent) {
        if (parent != nullptr) {
            if (isOnLeft()) {
                parent->left = nParent;
            } else {
                parent->right = nParent;
            }
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasRedChild() {
        return (left != nullptr && left->color == RED) ||
        (right != nullptr && right->color == RED);
    }
};

class RBTree {
    NodeRBT *root;

    // left rotates the given NodeRBT
    void leftRotate(NodeRBT *x) {
        // new parent will be NodeRBT's right child
        NodeRBT *nParent = x->right;

        // update root if current NodeRBT is root
        if (x == root)
        root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's left element
        x->right = nParent->left;
        // connect new parent's left element with NodeRBT
        // if it is not null
        if (nParent->left != nullptr)
        nParent->left->parent = x;

        // connect new parent with x
        nParent->left = x;
    }

    void rightRotate(NodeRBT *x) {
        // new parent will be NodeRBT's left child
        NodeRBT *nParent = x->left;

        // update root if current NodeRBT is root
        if (x == root)
        root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's right element
        x->left = nParent->right;
        // connect new parent's right element with NodeRBT
        // if it is not null
        if (nParent->right != nullptr)
        nParent->right->parent = x;

        // connect new parent with x
        nParent->right = x;
    }

    void swapColors(NodeRBT *x1, NodeRBT *x2) {
        COLOR temp;
        temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    void swapValues(NodeRBT *u, NodeRBT *v) {
        int temp;
        temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    // fix red red at given NodeRBT
    void fixRedRed(NodeRBT *x) {
        // if x is root color it black and return
        if (x == root) {
            x->color = BLACK;
            return;
        }

        // initialize parent, grandparent, uncle
        NodeRBT *parent = x->parent, *grandparent = parent->parent,
        *uncle = x->uncle();

        if (parent->color != BLACK) {
            if (uncle != nullptr && uncle->color == RED) {
                // uncle red, perform recoloring and recurse
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                fixRedRed(grandparent);
            } else {
                // Else perform LR, LL, RL, RR
                if (parent->isOnLeft()) {
                    if (x->isOnLeft()) {
                        // for left right
                        swapColors(parent, grandparent);
                    } else {
                        leftRotate(parent);
                        swapColors(x, grandparent);
                    }
                    // for left left and left right
                    rightRotate(grandparent);
                } else {
                    if (x->isOnLeft()) {
                        // for right left
                        rightRotate(parent);
                        swapColors(x, grandparent);
                    } else {
                        swapColors(parent, grandparent);
                    }

                    // for right right and right left
                    leftRotate(grandparent);
                }
            }
        }
    }

    // find NodeRBT that do not have a left child
    // in the subtree of the given NodeRBT
    NodeRBT *successor(NodeRBT *x) {
        NodeRBT *temp = x;

        while (temp->left != nullptr)
        temp = temp->left;

        return temp;
    }

    // find NodeRBT that replaces a deleted NodeRBT in BST
    NodeRBT *BSTreplace(NodeRBT *x) {
        // when NodeRBT have 2 children
        if (x->left != nullptr && x->right != nullptr)
        return successor(x->right);

        // when leaf
        if (x->left == nullptr && x->right == nullptr)
        return nullptr;

        // when single child
        if (x->left != nullptr){
        	return x->left;
	}else{
        	return x->right;
	}
    }

    // deletes the given NodeRBT
    void deleteNodeRBT(NodeRBT *v) {
        NodeRBT *u = BSTreplace(v);

        // True when u and v are both black
        bool uvBlack = ((u == nullptr || u->color == BLACK) && (v->color == BLACK));
        NodeRBT *parent = v->parent;

        if (u == nullptr) {
            // u is NULL therefore v is leaf
            if (v == root) {
                // v is root, making root null
                root = nullptr;
            } else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v->sibling() != nullptr)
                    // sibling is not null, make it red
                    v->sibling()->color = RED;
                }

                // delete v from the tree
                if (v->isOnLeft()) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            }
            delete v;
            return;
        }

        if (v->left == nullptr || v->right == nullptr) {
            // v has 1 child
            if (v == root) {
                // v is root, assign the value of u to v, and delete u
                v->val = u->val;
                v->left = v->right = nullptr;
                delete u;
            } else {
                // Detach v from tree and move u up
                if (v->isOnLeft()) {
                    parent->left = u;
                } else {
                    parent->right = u;
                }
                delete v;
                u->parent = parent;
                if (uvBlack) {
                    // u and v both black, fix double black at u
                    fixDoubleBlack(u);
                } else {
                    // u or v red, color u black
                    u->color = BLACK;
                }
            }
            return;
        }

        // v has 2 children, swap values with successor and recurse
        swapValues(u, v);
        deleteNodeRBT(u);
    }

    void fixDoubleBlack(NodeRBT *x) {
        if (x == root)
        // Reached root
        return;

        NodeRBT *sibling = x->sibling(), *parent = x->parent;
        if (sibling == nullptr) {
            // No sibiling, double black pushed up
            fixDoubleBlack(parent);
        } else {
            if (sibling->color == RED) {
                // Sibling red
                parent->color = RED;
                sibling->color = BLACK;
                if (sibling->isOnLeft()) {
                    // left case
                    rightRotate(parent);
                } else {
                    // right case
                    leftRotate(parent);
                }
                fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling->hasRedChild()) {
                    // at least 1 red children
                    if (sibling->left != nullptr && sibling->left->color == RED) {
                        if (sibling->isOnLeft()) {
                            // left left
                            sibling->left->color = sibling->color;
                            sibling->color = parent->color;
                            rightRotate(parent);
                        } else {
                            // right left
                            sibling->left->color = parent->color;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    } else {
                        if (sibling->isOnLeft()) {
                            // left right
                            sibling->right->color = parent->color;
                            leftRotate(sibling);
                            rightRotate(parent);
                        } else {
                            // right right
                            sibling->right->color = sibling->color;
                            sibling->color = parent->color;
                            leftRotate(parent);
                        }
                    }
                    parent->color = BLACK;
                } else {
                    // 2 black children
                    sibling->color = RED;
                    if (parent->color == BLACK)
                    fixDoubleBlack(parent);
                    else
                    parent->color = BLACK;
                }
            }
        }
    }

    // prints level order for given NodeRBT
    void levelOrder(NodeRBT *x) {
        if (x == NULL)
        // return if NodeRBT is null
        return;

        // queue for level order
	std::queue<NodeRBT *> q;
        NodeRBT *curr;

        // push x
        q.push(x);

        while (!q.empty()) {
            // while q is not empty
            // dequeue
            curr = q.front();
            q.pop();

            // print NodeRBT value
	    std::cout << curr->val << " ";

            // push children to queue
            if (curr->left != NULL)
            q.push(curr->left);
            if (curr->right != NULL)
            q.push(curr->right);
        }
    }

    // prints inorder recursively
    void inorder(NodeRBT *x) {
        if (x == NULL)
        return;
        inorder(x->left);
	std::cout << x->val << " ";
        inorder(x->right);
    }

public:
    // constructor
    // initialize root
    RBTree() { root = NULL; }

    NodeRBT *getRoot() { return root; }

    // searches for given value
    // if found returns the NodeRBT (used for delete)
    // else returns the last NodeRBT while traversing (used in insert)
    NodeRBT *search(int n) {
        NodeRBT *temp = root;
        while (temp != NULL) {
            if (n < temp->val) {
                if (temp->left == NULL)
                break;
                else
                temp = temp->left;
            } else if (n == temp->val) {
                break;
            } else {
                if (temp->right == NULL)
                break;
                else
                temp = temp->right;
            }
        }

        return temp;
    }

    // inserts the given value to tree
    void insert(int n) {
        NodeRBT *newNodeRBT = new NodeRBT(n);
        if (root == NULL) {
            // when root is null
            // simply insert value at root
            newNodeRBT->color = BLACK;
            root = newNodeRBT;
        } else {
            NodeRBT *temp = search(n);

            if (temp->val == n) {
                // return if value already exists
                return;
            }

            // if value is not found, search returns the NodeRBT
            // where the value is to be inserted

            // connect new NodeRBT to correct NodeRBT
            newNodeRBT->parent = temp;

            if (n < temp->val)
            temp->left = newNodeRBT;
            else
            temp->right = newNodeRBT;

            // fix red red voilaton if exists
            fixRedRed(newNodeRBT);
        }
    }

    // utility function that deletes the NodeRBT with given value
    void deleteByVal(int n) {
        if (root == NULL)
        // Tree is empty
        return;

        NodeRBT *v = search(n);

        if (v->val != n) {
		std::cout << "No NodeRBT found to delete with value:" << n << std::endl;
		return;
        }

        deleteNodeRBT(v);
    }

    // prints inorder of the tree
    void printInOrder() {
	std::cout << "Inorder: " << std::endl;
        if (root == NULL)
        std::cout << "Tree is empty" << std::endl;
        else
        inorder(root);
	std::cout << std::endl;
    }

    // prints level order of the tree
    void printLevelOrder() {
	    std::cout << "Level order: " << std::endl;
        if (root == NULL)
        std::cout << "Tree is empty" << std::endl;
        else
        levelOrder(root);
	std::cout << std::endl;
    }

    int findMax(){
    	NodeRBT *temp = root;
	while(temp->right != nullptr){
		temp = temp->right;
	}
	return temp->val;
    }

    int findMin(){
    	NodeRBT *temp = root;
	while(temp->left != nullptr){
		temp = temp->left;
	}
	return temp->val;
    }


};
