#include <iostream>

using namespace std;

#define MAX 100

#ifndef _HEADWER_H_
#define _HEADWER_H_
struct ENode{
	ENode(int val):index(val),next(nullptr){};
	int index;
	ENode* next;
};

struct VNode{
	char data;
	ENode* first_child;
	VNode():first_child(nullptr){};
};


class Kruskal{
public:
	Kruskal(char v[],int v_size,char e[][2],int e_size);
	~Kruskal();
public:
	void print();
	char get_char();
	void link_last(ENode* start,ENode* end);
	int get_position(char c);
	void kruskal();
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Kruskal::Kruskal(char v[],int v_size,char e[][2],int e_size) {
	vlen = v_size;
	elen = e_size;
	for (int i = 0; i < vlen; i++) {
		vnode[i]->data = v[i];
	}
	for (int i = 0; i < elen; i++) {
		char c1 = elen[i][0];
		char c2 = elen[i][1];
		int p1 = get_position(c1);
		int p2 = get_position(c2);
		ENode* node = new ENode(p1);
		if (v[p1]->first_child == nullptr) {
			v[p1]->first_child = node;
		} else {
			link_last(v[p1]->first_child,node);
		}
		node = new ENode(p2);
		if (v[p2]->first_child == nullptr) {
			v[p2]->first_child = node;
		} else {
			link_last(v[p2]->first_child,node);
		}
		node = nullptr;
	}
}
Kruskal::~Kruskal() {
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
void Kruskal::print() {
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

char Kruskal::get_position(char c) {
	for (int i = 0; i < vlen; i++) {
		if (c == vnode[i].data) {
			return i;
		}
	}
	return 0;
}

void Kruskal::link_last(ENode* start,ENode* end) {
	ENode* p = link;
	while (p->next) {
		p = p->next;
	}
	p->next = node;
}
char Kruskal::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}
void Kruskal::kruskal() {

}


#endif