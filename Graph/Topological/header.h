#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


#ifndef _HEADWE_H_

#define _HEADWE_H_

#define MAX 100

struct Enode{
	Enode(int data):index(data){next = nullptr;}
	int index;
	Enode* next;
	
};

struct Vnode{
	Vnode():first_next(nullptr){};
	char data;
	Enode* first_next;
};


class Graph{
public:
	Graph(){};
	Graph(char v[],int vsize,char e[][2],int esize);
	~Graph(){};
public:
	int get_position(char c);
	void print();
	char get_char();
	void link_last(Enode* vn,Enode* en);
	int topological_sort();
private:
	Vnode v[MAX];
	int vlen;
	int elen;
};

Graph::Graph(char vn[],int vsize,char e[][2],int esize) {
	vlen = vsize;
	elen = esize;
	for (int i = 0; i < vlen; i++) {
		this->v[i].data = vn[i];
	}
	for (int i = 0; i < elen; i++) {
		int p1 = get_position(e[i][0]);
		int p2 = get_position(e[i][1]);

		Enode* p = new Enode(p2);
		if (v[p1].first_next == nullptr) {
			v[p1].first_next = p;
		} else {
			link_last(v[p1].first_next,p);
		}
	}

}

int Graph::get_position(char c) {
	for (int i = 0; i < vlen; i++) {
		if (v[i].data == c) {
			return i;
		}
	}
	return 0;

}

void Graph::print() {
	for (int i = 0; i < vlen; i++) {
		cout<<v[i].data<<"("<<i<<"):";
		Enode* node = v[i].first_next;
		while(node) {
			cout<<node->index<<v[node->index].data<<" ";
			node = node->next;
		}
		cout<<endl;
	}
}

char Graph::get_char() {
	char ch;
	do{
		cin>>ch;
	}while(ch<'A'||ch>'Z');
	return ch;
}

void Graph::link_last(Enode* vn,Enode* en) {
	Enode* p = vn;
	while(p->next) {
		p = p->next;
	}
	p->next = en;
}

int Graph::topological_sort() {
	int queue[MAX] = {0};			//入度为0的节点入队列
	int ins[MAX] = {0};			//统计所有的入度
	char tops[MAX] = {0};			//拓扑排序结果
	int head = 0; 		//遍历queue的指针
	int rear = 0; 		//遍历queue的指针
	int front_q = 0; 	//入度为0的第一个节点位置
	int tops_index = 0;	//拓扑排序结果指针

	// ins = new int[vlen];
	// queue = new int[vlen];
	// tops = new char[vlen];
	// memset(ins,0,sizeof(ins));
	// memset(queue,0,sizeof(queue));
	// memset(tops,0,sizeof(tops));
	Enode* node = nullptr;

	for (int i = 0; i < vlen; i++) {
		node = v[i].first_next;
		while (node) {
			ins[node->index]++;
			node = node->next;
		}
	}
	
	for (int i = 0; i < vlen; i++) {
		if (ins[i] == 0) {
			queue[rear++] = i;
		}
	}

	

	while (head != rear) {
		front_q = queue[head++];
		tops[tops_index++] = v[front_q].data;
		node = v[front_q].first_next;

		while (node) {
			ins[node->index]--;
			if (ins[node->index] == 0) {
				queue[rear++] = node->index;
			}
			node = node->next;
		}
	}
	if (tops_index != vlen) {
		cout<<"The Graph has a cycle";
		// delete queue;
		// delete ins;
		// delete tops;
		return 1;
	}
	//打印拓扑排序结果
	for (int i = 0; i < vlen; i++) {
		cout<<tops[i]<<" ";
	}
	// delete queue;
	// delete ins;
	// delete tops;
	return 0;
}

#endif