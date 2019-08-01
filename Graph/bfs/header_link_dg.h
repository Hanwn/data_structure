#include <iostream>
#include <queue>
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
	VNode():first_child(nullptr);
};

class Dg_link{
public:
	Dg_link(){};
	Dg_link(char v[],int v_size;char e[][2],int e_size);
	~Dg_link();
public:
	void print();
	char get_char();
	int get_position(char c);
	void bfs();
	void link_last(ENode* head,ENode* node);
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

	for (int i = 0; i < vlen; i++) {
		this->vnode[i].data = v[i];
	}

	for (int i = 0; i < elen; i++) {
		char c1 = e[i][0];
		char c2 = e[i][1];

		int p1 = get_position(c1);
		int p2 = get_position(c2);

		ENode* node1 = new ENode(p2);

		if (this->vnode[p1].first_child == nullptr) {
			this->vnode[p1].first_child = node1;
		} else {
			link_last(this->vnode[p1].first_child,node1);
		}

	}

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

int Dg_link::get_position(char c) {
	for (int i = 0; i < vlen; i++) {
		if (c == vnode[i].data) {
			return i;
		}
	}
	return 0;
}

void Dg_link::link_last(ENode* link,ENode* node) {
	ENode* p = link;
	while (p->next) {
		p = p->next;
	}
	p->next = node;
}

char Dg_link::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

void bfs() {
	
}


#endif
