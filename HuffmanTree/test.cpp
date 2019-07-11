#include <iostream>
#include "header.h"

using namespace std;

int main(){

	int a[] = {5,6,8,7,15};
	int ilen = sizeof(a)/sizeof(int);
	Huffman* h = new Huffman();
	h->create(a,ilen);
	h->preOrder();
	return 0;
}