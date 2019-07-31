#include <iostream>
using namespace std;

const int branch_num = 26; 

#ifndef _HEADER_H_

#define _HEADER_H_
struct Node{
	char data;
	Node* branch[branch_num];
};

class Trie{
public:
	Trie(){};
	~Trie(){};
public:
	void insert();
	void del();
	void find();
private:

};



#endif