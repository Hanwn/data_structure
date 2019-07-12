#include <iostream>

using namespace std;

#ifndef _HEADER_LINK_H_
#define _HEADER_LINK_H_

#define MAX 100

struct ENode{
	int index;
	ENode* next;
};

struct VNode{
	VNode():first(nullptr){};
	char data;
	ENode* first;
};

class DG{
public:
	DG();
	DG(char v[],int vsize,char e[][2],int esize);
	~DG();
public:
	void print();
	char getChar();
	int getPositon(char ch);
	void linkLast(ENode* vnode,ENode* enode);
private:
	VNode varr[MAX];
	int vlen;
	int elen;
};

DG::DG(){}

DG::DG(char v[],int vsize,char e[][2],int esize){
	vlen = vsize;
	elen = esize;
	
	for (int i = 0; i < vlen ; i++){
		varr[i].data = v[i];
		// varr[i].first = nullptr;
	}

	for(int i = 0 ; i < elen ; i++){
		char c1 = e[i][0];
		char c2 = e[i][1];

		int p1 = getPositon(c1);
		int p2 = getPositon(c2);

		ENode* node = new ENode();
		node->index = p2;

		if(varr[p1].first == nullptr){
			varr[p1].first = node;
		}else{
			linkLast(varr[p1].first,node);
		}

	}
}

DG::~DG(){}

void DG::print(){
	for (int i = 0; i < vlen ;i++){
		ENode* p = varr[i].first;
		cout<<varr[i].data<<":";
		while(p){
			cout<<varr[p->index].data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

int DG::getPositon(char ch){
	for(int i = 0; i < vlen; i++){
		if(varr[i].data == ch){
			return i;
		}
	}
	return -1;
}

char DG::getChar(){
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

void DG::linkLast(ENode* node1, ENode * node2){
	while(node1->next){
		node1 = node1->next;
	}
	node1->next = node2;
}

#endif