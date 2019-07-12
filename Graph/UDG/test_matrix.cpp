#include <iostream>
#include "header_matrix.h"
using namespace std;

int main(){
	char v[] = {'a','b','c','d','e','f','g'};
	char e[][2] = {
		{'a','c'},
		{'a','d'},
		{'a','f'},
		{'b','c'},
		{'c','d'},
		{'e','g'},
		{'f','g'}
	};
	int vlen = sizeof(v)/sizeof(char);
	int elen = sizeof(e)/sizeof(e[0]);
	MatrixUDG *udg = nullptr;
	udg = new MatrixUDG(v,vlen,e,elen);
	udg->print();
	return 0;
}