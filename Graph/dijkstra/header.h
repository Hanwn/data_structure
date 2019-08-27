#include <iostream>
using namespace std;

#define MAX 100

#ifndef _HEADER_H_
#define _HEADER_H_

struct EData{
	char start;
	char end;
	int weight;
	EData(){};
	EData(char s,char e,int w){
		start = s;
		end = e;
		weight = w;
	};
};

struct ENode{
	int index;
	int weight;
	ENode* next;
	ENode(int val,int w){
		index = val;
		weight = w;
		next = nullptr;
	}
};

struct VNode{
	char data;
	ENode* first_child;
	VNode(){first_child = nullptr;}
};

class Dijkstra{
public:
	Dijkstra(){};
	Dijkstra(char v[],int v_size,EData* e[],int e_size);
	~Dijkstra();
public:
	void print();
	int get_pos(char ch);
	void link_last(ENode* s,ENode* e);
	char getChar();
	int get_weight(int s,int e);
	void dijkstra(int s);
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Dijkstra::Dijkstra(char v[],int v_size,EData* e[],int e_size) {
	elen = e_size;
	vlen = v_size;
	for (int i = 0; i < vlen; i++) {
		vnode[i].data = v[i];
	}

	for (int i = 0; i < elen; i++) {
		char c1 = e[i]->start;
		char c2 = e[i]->end;
		int weight = e[i]->weight;

		int p1 = get_pos(c1);
		int p2 = get_pos(c2);

		ENode* p = new ENode(p1,weight);
		if (vnode[p2].first_child == nullptr) {
			vnode[p2].first_child = p;
		} else {
			link_last(vnode[p2].first_child,p);
		}
		p = new ENode(p2,weight);
		if (vnode[p1].first_child == nullptr) {
			vnode[p1].first_child = p;
		} else {
			link_last(vnode[p1].first_child,p);
		}

	}
}

Dijkstra::~Dijkstra() {

}

void Dijkstra::link_last(ENode* s,ENode* e) {
	ENode* p = s;
	while (p->next) {
		p = p->next;
	}
	p->next = e;
}
int Dijkstra::get_pos(char ch) {
	for (int i = 0; i < vlen; i++) {
		if (ch == vnode[i].data) {
			return i;
		}
	}
	return 0;
}
void Dijkstra::print() {
	for (int i = 0; i < vlen; i++) {
		cout<<vnode[i].data<<":";
		ENode* p = vnode[i].first_child;
		while (p) {
			cout<<p->index<<vnode[p->index].data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

int Dijkstra::get_weight(int s,int e) {
	if (s == e) {
		return 0;
	}
	ENode* p = vnode[s].first_child;
	int min = INT_MAX;
	while (p) {
		if (p->weight  == e) {
			return e;
		}
		p = p->next;
	}

	return min;
}

void Dijkstra::dijkstra(int s) {
	int prev[MAX] = {0};
	int dist[MAX] = {0};

	int i,j,k;
	int min;
	int temp;
	int flag[MAX] = {0};

	for (i = 0; i < vlen; i++) {
		dist[i] = get_weight(s,i);
	}
	flag[s] = 1;
	dist[s] = 0;

	for (i = 1; i < vlen; i++) {
		min = INT_MAX;

		for (j = 0; j < vlen; j++) {
			if (flag[j] == 0 && dist[j] < min) {
				min = dist[j];
				k = j;
			}
		}
		flag[k] = 1;

		for (j = 0; j < vlen; j++) {
			temp = get_weight(k,j);
			temp = (temp == INT_MAX?INT_MAX:(min + temp
				));
			if (flag[j] == 0 && temp < dist[j]) {
				dist[j] = temp;
				prev[j] = k;
			}
		}
	}
	cout<<"dijkstra(" << vnode[s].data<<"):"<<endl;
	for (i = 0; i < vlen; i++) {
		cout <<"shortest("<<vnode[s].data<<","<<vnode[i].data<<")="<<dist[i]<<endl;
	}
}


#endif