#include <iostream>

using namespace std;


#ifndef _HEADWE_H_

#define _HEADWE_H_

#define MAX 100

struct Endoe{
	int index;
	Endoe* next;
	
};

struct Vnode{
	Vnode():first_next(nullptr){};
	char data;
	Endoe* first_next;
};


class Graph{
public:
	Graph(){};
	Graph(char v[],int vsize,char e[][2],int esize);
	~Graph(){};
public:
	int get_position();
	void print();
	char get_char();
	void link_last(Enode* vnode,Enode* enode);
private:
	Vnode v[MAX];
	int vlen;
	int elen;
};

Graph::Graph(char v[],int vsize,char e[][2],int esize) {

}

int Graph::get_position() {

}

void Graph::print() {

}

char Graph::get_char() {

}

void Graph::link_last(Enode* vnode,Enode* enode) {
	
}

#endif