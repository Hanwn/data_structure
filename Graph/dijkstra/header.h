#include <iostream>
using namespace std;

#define MAX 100

#ifndef _HEADER_H_
#define _HEADER_H_

struct ENode{
	int index;
	ENode* next;
};

struct VNode{
	char data;
	ENode* first_child;
};

class Graph{
public:
	Graph(){};
	Graph();
	~Graph()
public:
	void print();
	int getPosition(char ch);
	void linkLast(Enode* list,Enode* node);
	char getChar();
	void dfs()
private:
	VNode v[MAX];
	int vlen;
	int elen;
};

Graph() {
	s
}

#endif