#include <iostream>

using namespace std;

#define MAX 100

#ifndef _HEADWER_H_
#define _HEADWER_H_

struct EData{
	char start;
	char end;
	int weight;
	EData(){};
	EData(char s,char e,int w) {
		start = s;
		end = e;
		weight = w;
	}
};

struct ENode{
	ENode(int val,int data):index(val),weight(data),next(nullptr){};
	int index;
	int weight;
	ENode* next;
};

struct VNode{
	char data;
	ENode* first_child;
	VNode():first_child(nullptr){};
};


class Kruskal{
public:
	Kruskal(char v[],int v_size,EData *e[],int e_size);
	~Kruskal();
public:
	void print();
	char get_char();
	void link_last(ENode* start,ENode* end);
	int get_position(char c);
	void kruskal();
	EData* get_edges();
	void sort_edges(EData* edges);
	int get_end(int* vends,int pos);
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};


Kruskal::Kruskal(char v[],int v_size,EData *e[],int e_size) {
	vlen = v_size;
	elen = e_size;
	for (int i = 0; i < vlen; i++) {
		vnode[i].data = v[i];
	}
	for (int i = 0; i < elen; i++) {
		char c1 = e[i]->start;
		char c2 = e[i]->end;
		int weight = e[i]->weight;
		int p1 = get_position(c1);
		int p2 = get_position(c2);
		ENode* node = new ENode(p2,weight);
		if (vnode[p1].first_child == nullptr) {
			vnode[p1].first_child = node;
		} else {
			link_last(vnode[p1].first_child,node);
		}
		node = new ENode(p1,weight);
		if (vnode[p2].first_child == nullptr) {
			vnode[p2].first_child = node;
		} else {
			link_last(vnode[p2].first_child,node);
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

int Kruskal::get_position(char c) {
	for (int i = 0; i < vlen; i++) {
		if (c == vnode[i].data) {
			return i;
		}
	}
	return 0;
}

void Kruskal::link_last(ENode* start,ENode* end) {
	ENode* p = start;
	while (p->next) {
		p = p->next;
	}
	p->next = end;
}
char Kruskal::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}


EData* Kruskal::get_edges() {
	EData* edges = nullptr;
	ENode* enode = nullptr;
	edges = new EData[elen];
	int index = 0;
	for (int i = 0; i < vlen; i++) {
		enode = vnode[i].first_child;
		while (enode) {
			if (enode->index > i) {
				edges[index].start = vnode[i].data;
				edges[index].end = vnode[enode->index].data;
				edges[index].weight = enode->weight;
				index++;
			}
			enode = enode->next;
		}
	}
	return edges;
}

void Kruskal::sort_edges(EData* edges) {
	for (int i = 0; i < elen; i++) {
		for (int j = i + 1; j < elen; j++) {
			if (edges[i].weight > edges[j].weight) {
				swap(edges[i],edges[j]);
			}
		}
	}
}

int Kruskal::get_end(int* vends,int pos) {
	while (vends[pos]) {
		pos = vends[pos];
	}
	return pos;
}

void Kruskal::kruskal() {
	EData res[MAX];
	int index = 0;
	EData* edges = get_edges();
	int vends[MAX] = {0};

	sort_edges(edges);

	for (int i = 0; i < elen; i++) {
		int p1 = get_position(edges[i].start);
		int p2 = get_position(edges[i].end);

		int m = get_end(vends,p1);
		int n = get_end(vends,p2);


		if (m != n) {
			vends[m] = n;
			res[index++] = edges[i];
		}
	}
	delete edges;
	int len = 0;
	for (int i = 0; i < index; i++) {
		len += res[i].weight;
		cout<<res[i].weight<<endl;
	}
	cout<<"Kruskal = "<<len<<":";
	for (int i = 0; i < index; i++) {
		cout<<"("<<res[i].start<<","<<res[i].end<<")";
	}
	cout<<endl;
}


#endif