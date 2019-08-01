#include <iostream>

using namespace std;

#define MAX 100
#ifndef _HEADER_H_
#define _HEADER_H_
struct ENode{
	int index;
	ENode* next;
	ENode():next(nullptr){};
	ENode(int val):index(val),next(nullptr){};
};

struct VNode{
	char data;
	ENode* first_child;
	VNode():first_child(nullptr){};
};


class Dg_link
{
public:
	Dg_link(){};
	Dg_link(char v[],int v_size,char e[][2],int e_size);
	~Dg_link();
public:
	char get_char();
	int get_position(char ch);
	void dfs();
	void dfs(int i,int *visted);
	void link_last(ENode* link,ENode* node);
	void print();
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Dg_link::~Dg_link() {
	for (int i = 0 ; i < vlen; i++) {
		if (vnode[i].first_child) {
			ENode* p = vnode[i].first_child;
			while(p) {
				ENode* temp = p;
				p = p->next;
				delete temp;
			}
			p = nullptr;
		}
	}
}

Dg_link::Dg_link(char v[],int v_size,char e[][2],int e_size) {
	vlen = v_size;
	elen = e_size;
	for (int i = 0 ; i < vlen; i++) {
		this->vnode[i].data = v[i];
	}

	for (int i = 0; i < elen; i++) {
		char c1 = e[i][0];
		char c2 = e[i][1];

		int p1 = get_position(c1);
		int p2 = get_position(c2);

		ENode* node1 = new ENode(p2);
		if (vnode[p1].first_child == nullptr) {
			vnode[p1].first_child = node1;	
		} else {
			link_last(vnode[p1].first_child,node1);
		}
	}
}
char Dg_link::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

int Dg_link::get_position(char c) {
	for (int i = 0 ; i < vlen; i++) {
		if (c == vnode[i].data) {
			return i;
		}
	}
	return -1;
}

void Dg_link::print() {
	for (int i = 0; i < vlen; i++) {
	cout<<i<<"("<<vnode[i].data<<"):";
	ENode* temp = vnode[i].first_child;
	while (temp) {
		cout<<"->"<<temp->index<<"("<<vnode[temp->index].data<<")";
		temp = temp->next;
		}
	cout<<endl;
	}
}

void Dg_link::link_last(ENode* head,ENode* node) {
	ENode* p = head;
	while (p->next) {
		p = p->next;
	}
	p->next = node;
}

void Dg_link::dfs() {
	int visted[MAX];
	cout<<"DFS:";
	for (int i = 0; i < vlen; i++) {
		visted[i] = 0;
	}
	for (int i = 0 ; i < elen; i++) {
		if (!visted[i]) {
			dfs(i,visted);
		}
	}
}

void Dg_link::dfs(int i,int *visted) {
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