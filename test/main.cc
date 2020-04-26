#include "RBT.hh"
#include <iostream>

int main(){
	RBTree rbt;
	rbt.insert(1);
	rbt.insert(2);
	rbt.insert(3);
	rbt.insert(4);
	rbt.insert(11);
	rbt.insert(12);
	rbt.insert(5);
	rbt.insert(6);
	rbt.insert(9);
	Node *rbtRoot = rbt.getRoot();
	rbtRoot->printNode();
	//std::cout << rbtRoot->printNode() << std::endl;
	rbt.printInOrder();
	rbt.printLevelOrder();

	std::cout << "~~~ after deleting 1,2,3 ~~~" << std::endl;
	rbt.deleteByVal(1);
	rbt.deleteByVal(2);
	rbt.deleteByVal(3);

	rbtRoot = rbt.getRoot();
	rbtRoot->printNode();
	//std::cout << rbtRoot->printNode() << std::endl;
	rbt.printInOrder();
	rbt.printLevelOrder();
	return 0;
}
