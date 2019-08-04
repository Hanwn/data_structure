#include <iostream>

#include "header.h"

using namespace std;

int main(){
	MinHeap m = MinHeap(10);
	for(int i = 0; i < 10; i++ ){
		m.insert(i);
	}
	m.print();
	return 0;
}