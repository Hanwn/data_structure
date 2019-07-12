#include <iostream>
#include "header_matrix.h"
using namespace std;

int main(){
	char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	char edges[][2] = {
	    {'A', 'B'}, 
	    {'B', 'C'}, 
	    {'B', 'E'}, 
	    {'B', 'F'}, 
	    {'C', 'E'}, 
	    {'D', 'C'}, 
	    {'E', 'B'}, 
	    {'E', 'D'}, 
	    {'F', 'G'}}; 
	int vlen = sizeof(vexs)/sizeof(vexs[0]);
	int elen = sizeof(edges)/sizeof(edges[0]);
	DG* dg = new DG(vexs, vlen, edges, elen);
	dg->print();
}
