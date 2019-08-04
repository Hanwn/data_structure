#include <iostream>
#include <vector>
#include "header.h"
using namespace std;


int main() {
	vector<int> v = {1,2,8,9,10};
	SegmentTree* s = new SegmentTree(v);
	s->print();


	return 0;
}