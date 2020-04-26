#include "RBT.hh"

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
	rbt.printInOrder();
	rbt.printLevelOrder();

	rbt.deleteByVal(1);
	rbt.deleteByVal(2);
	rbt.deleteByVal(3);
	rbt.printInOrder();
	rbt.printLevelOrder();
	return 0;
}
