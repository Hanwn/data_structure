#include <iostream>
#include <vector>
#include "header.h"
using namespace std;


int main() {
	vector<int> v = {1,2,8,9,10};
	SegmentTree* s = new SegmentTree(v);
	s->print();
	s->sumRange(0,2);
	s->update(1,7);
	cout<<endl;
	s->print();
	s->sumRange(0,2);
	return 0;
}