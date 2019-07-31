#include <iostream>

using namespace std;

#define MAX 100

#ifndef _HEADER_H
#define _HEADER_H

struct ENode{
	int index;
	ENode* next;
};

struct VNode{
	VNode():first_child(nullptr){};
	char data;
	ENode* first_child;
};

class Graph{
public:
	Graph(){};
	Graph(char v[],int v_size,char e[][2],int e_size);
	~Graph(){};
public:
	void print();
	int get_position(char ch);
	void link_last(ENode* link,ENode* node);
	char get_char();
	void dfs();
	void dfs(int i,int *visted);
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Graph::Graph(char v[],int v_size,char e[][2],int e_size) {
	vlen = v_size;
	elen = e_size;

	for (int i = 0; i < vlen; i++) {
		this->vnode[i].data = v[i];
	}

	for (int i = 0; i < elen; i++) {
		char c1 = e[i][0];
		char c2 = e[i][1];

		int p1 = get_position(c1);
		int p2 = get_position(c2);

		ENode* node1 = new ENode();
		node1->index = p2;

		if (this->vnode[p1].first_child == nullptr) {
			this->vnode[p1].first_child = node1;
		} else {
			link_last(this->vnode[p1].first_child,node1);
		}

		ENode* node2 = new ENode();
		node2->index = p1;

		if (this->vnode[p2].first_child == nullptr) {
			this->vnode[p2].first_child = node2;
		} else {
			link_last(this->vnode[p2].first_child,node2);
		}

	}

}
void Graph::print() {
	for (int i = 0; i < vlen; i++) {
		cout<<i<<"("<<vnode[i].data<<"):";
		ENode* temp = vnode[i].first_child;
		while (temp) {
			cout<<temp->index<<"("<<vnode[temp->index].data<<")";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int Graph::get_position(char c) {
	for (int i = 0; i < vlen; i++) {
		if (c == vnode[i].data) {
			return i;
		}
	}
	return 0;
}

void Graph::link_last(ENode* link,ENode* node) {
	ENode* p = link;
	while (p->next) {
		p = p->next;
	}
	p->next = node;
}

char Graph::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

void Graph::dfs() {
	int i;
	int visted[MAX];

	for (i = 0; i < vlen; i++) {
		visted[i] = 0;
	}

	cout<<"DFS:";
	for (i = 0; i < elen; i++) {
		if (!visted[i]) {
			dfs(i,visted);
		}
	}
	cout<<endl;
}
void Graph::dfs(int i,int *visted) {
	visted[i] = 1;
	cout<<vnode[i].data<<" ";
	ENode* node = vnode[i].first_child;
	while (node) {
		if (!visted[node->index]) {
			dfs(node->index,visted);
		}
		node = node->next;
	}
}

#endif