#include <iostream>

using namespace std;

const int MAX = 100;


#ifndef _HEADER_H_

struct EData{
	char start;
	char end;
	int weight;
	EData(){};
	EData(char s,char e,int w){
		start = s;
		end = e;
		weight = w;
	}
};

struct ENode{
	int index;
	int weight;
	ENode* next;
	ENode(int val,int w):index(val),weight(w),next(nullptr){};
};

struct VNode{
	char data;
	ENode* first_next;
	VNode():first_next(nullptr){};
};

class Prim{
public:
	Prim(char* v,int v_size, EData* e[],int e_size);
	~Prim();
public:
	void link_last(ENode* start,ENode* end);
	int get_pos(char c);
	void prim(int start);
	int get_weight(int start,int end);
	void print();

private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Prim::Prim(char c[],int v_size,EData* e[],int e_size){
	vlen = v_size;
	elen = e_size;
	for (int i = 0; i < vlen; i++) {
		vnode[i].data = c[i];
	}
	ENode* p = nullptr;
	for (int i = 0; i < elen; i++) {
		char c1 = e[i]->start;
		char c2 = e[i]->end;
		int weight = e[i]->weight;
		int p1 = get_pos(c1);
		int p2 = get_pos(c2);

		p = new ENode(p2,weight);

		if (vnode[p1].first_next == nullptr) {
			vnode[p1].first_next = p;
		} else {
			link_last(vnode[p1].first_next,p);
		}

		p = new ENode(p1,weight);
		if (vnode[p2].first_next == nullptr) {
			vnode[p2].first_next = p;
		} else {
			link_last(vnode[p2].first_next,p);
		}
		p = nullptr;
	}
}
Prim::~Prim(){}


void Prim::link_last(ENode* start,ENode* end){
	ENode* p = start;
	while(p->next) {
		p = p->next;
	}
	p->next = end;
}

int Prim::get_pos(char c){
	for (int i = 0; i < vlen; i++) {
		if (vnode[i].data == c) {
			return i;
		}
	}
	return 0;
}

int Prim::get_weight(int start,int end) {
	ENode* p = nullptr;

	if (start == end) {
		return 0;
	}
	p = vnode[start].first_next;
	while (p) {
		if (end == p->index) {
			return p->weight;
		}
		p = p->next;
	}
	return INT_MAX;
}

void Prim::prim(int start) {
	int index = 0;
	int i,j,min,k,m,n,temp;
	char prims[MAX];
	int weights[MAX];

	prims[index++] = vnode[start].data;

	for (i = 0; i < vlen; i++) {
		weights[i] = get_weight(start,i);
	}

	for (i = 0; i < elen; i++) {
		if (start == i) {
			continue;
		}
		k = 0;
		j = 0;
		min = INT_MAX;
		while (j < vlen) {
			if (weights[j] != 0 && weights[j] < min) {
				min = weights[j];
				k = j;
			}
			j++;
		}
		prims[index++] = vnode[k].data;
		cout<<prims[index - 1];
		weights[k] = 0;

		for (j = 0; j < vlen; j++) {
			temp = get_weight(k,j);
			if (weights[j] != 0 && temp < weights[j]) {
				weights[j] = temp;
			}

		}
	}
	int sum = 0;
	for (i = 1; i < index; i++) {
		min = INT_MAX;
		n = get_pos(prims[i]);
		for (j = 0; j < i; j++) {
			m = get_pos(prims[j]);
			temp = get_weight(m,n);
			if (temp < min) {
				min = temp;
			}
		}
		sum += min;
	}
	cout<<"PRIM("<<vnode[start].data <<")="<<sum<<":";
	for (i = 0; i < index; i++) {
		cout << prims[i]<<" ";
	}
	cout<<endl;
}
void Prim::print() {
	for (int i = 0; i < vlen; i++) {
		ENode* p = vnode[i].first_next;
		while(p) {
			cout<<p->index<<"("<<vnode[p->index].data<<")";
			p = p->next;
		}
		cout<<endl;
	}
}

#define _HEADER_H_
#endif