#include <iostream>
#include "header.h"

using namespace std;

int main(){

	MaxHeap h = MaxHeap(10);
	for(int i = 0; i < 10 ; i++){
		h.insert(i);
	}
	h.print();
	return 0;
}