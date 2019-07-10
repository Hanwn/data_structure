#include "header.h"
#include <iostream>

using namespace std;

int main(){
	AVLTree a = AVLTree();
	a.insert(5);
	a.insert(2);
	a.insert(6);
	a.insert(1);
	a.insert(7);
	a.insert(3);
	a.insert(4);
	a.remove(3);
	a.preOrder();
	return 0;
}