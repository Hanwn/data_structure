#include "header.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	BSTree* b = new BSTree();
	b->insert(5);
	b->insert(5);
	b->insert(9);
	b->insert(4);
	b->insert(6);
	b->insert(7);
	b->insert(3);
	b->insert(1);
	b->preOrder();
	b->remove(5);
	cout<<endl;
	b->preOrder();
	cout<<endl;
	cout<<"max:"<<b->find_max()<<"  min:"<<b->find_min()<<endl;
	return 0;
}