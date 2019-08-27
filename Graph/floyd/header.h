#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

#ifndef _HEADER_H_

#define _HEADER_H_

struct EData{
	char start;
	char end;
	int weight;
	EData(char s,char e,int w) {
		start = s;
		end = e;
		weight = w;		
	}
};
struct ENode{
	int index;
	int weight;
	ENode* next;
	ENode(int val,int w) {
		index = val;
		weight = w;
		next = nullptr;
	}
};
struct VNode{
	char data;
	ENode* first_child;
	VNode() {
		first_child = nullptr;
	}
};

class Floyd{
public:
	Floyd(){};
	Floyd(char v[],int v_size,EData* e[],int e_size);
	~Floyd(){};
public:
	int get_pos(char ch);
	void link_last(ENode* s,ENode* e);
	void print();
	void floyd();
	int get_weight(int s,int e);
private:
	VNode vnode[MAX];
	int vlen;
	int elen;
};

Floyd::Floyd(char v[],int v_size,EData* e[],int e_size) {
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

		ENode* p = new ENode(p2,weight);

		if (vnode[p1].first_child == nullptr) {
			vnode[p1].first_child = p;
		} else {
			link_last(vnode[p1].first_child,p);
		}

		p = new ENode(p1,weight);
		if (vnode[p2].first_child == nullptr) {
			vnode[p2].first_child = p;
		} else {
			link_last(vnode[p2].first_child,p);
		}

	}
}

int Floyd::get_pos(char ch) {
	for (int i = 0; i < vlen; i++) {
		if (vnode[i].data == ch) {
			return i;
		}
	}
	return 0;
}

void Floyd::link_last(ENode* s,ENode* e) {
	ENode* p = s;
	while (p->next) {
		p = p->next;
	}
	p->next = e;
}

void Floyd::print() {
	for (int i = 0; i < vlen; i++) {
		ENode* p = vnode[i].first_child;
		cout<<vnode[i].data<<":";
		while (p) {
			cout<<p->index<<vnode[p->index].data<<" ";
			p = p->next;
		}
		cout<<endl;
	}
}

int Floyd::get_weight(int s,int e) {
	if (s == e) {
		return 0;
	}
	ENode* p = vnode[s].first_child;
	while (p) {
		if (p->index == e) {
			return p->weight;
		}
		p = p->next;
	}
	return INT_MAX;
}

void Floyd::floyd() {
	int i,j,k;
	int temp;
	int path[MAX][MAX] = {0};
	int dist[MAX][MAX] = {0};

	for (int i = 0; i < vlen; i++) {
		for (int j = 0; j < vlen; j++) {
			dist[i][j] = get_weight(i,j);
			path[i][j] = j;
		}
	}

	for (k = 0; k < vlen; k++) {
		for (i = 0; i < vlen; i++) {
			for (j = 0; j < vlen; j++) {
				temp = (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)?INT_MAX:(dist[i][k] + dist[k][j]);
				if (dist[i][j] > temp) {
					dist[i][j] = temp;
					path[i][j] = path[i][k];
				}
			}
		}
	}
	cout<<"Floyd:"<<endl;
	for (i = 0; i < vlen; i++) {
		for (j = 0; j < vlen; j++) {
			cout<<setw(2)<<dist[i][j]<<" ";
		}
		cout<<endl;
	}

}

#endif