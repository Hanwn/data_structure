#include <iostream>

using namespace std;

#ifndef _HEADER_LINK_

#define _HEADER_LINK_

#define MAX 100

struct Enode{
	int ivex;
	Enode* nextEdge;	
};

struct Vnode{
	char data;
	Enode* firstEdge;
};


class LinkUDG{
public:
	LinkUDG();
	LinkUDG(char vexs[],int vlen,char edges[][2],int elen);
	~LinkUDG();
public:
	void print();
	int getPosition(char ch);
	void linkLast(Enode* list,Enode* node);
	char getChar();
private:
	int vexnum;
	int edgenum;
	Vnode vexs[MAX];

};

LinkUDG::LinkUDG(){
	cout<<"please input vertex number:";
	cin>>vexnum;
	cout<<"please input edge number:";
	cin>>edgenum;
	if(vexnum<1||edgenum<1||(edgenum>(vexnum*(vexnum - 1)))){
		cout<<"invalid parameters";
		return;
	}
	for (int i = 0 ; i < vexnum; i++){
		vexs[i].data = getChar();
	}

	for (int i = 0; i < edgenum; i++){
		cout<<"edge("<<i<<"):";
		int c1 = getChar();
		int c2 = getChar();
		int p1 = getPosition(c1);
		int p2 = getPosition(c2);

		Enode* node = new Enode();
		node->ivex = p2;
		if(vexs[p1].firstEdge == nullptr){
			vexs[p1].firstEdge = node;
		}else{
			linkLast(vexs[p1].firstEdge,node);
		}
		delete node;

		node = new Enode();
		node->ivex = p1;
		if(vexs[p2].firstEdge == nullptr){
			vexs[p2].firstEdge = node;
		}else{
			linkLast(vexs[p2].firstEdge,node);
		}
	}
}
LinkUDG::LinkUDG(char vexs[],int vlen,char edges[][2],int elen){
	Enode* node1,*node2;
	vexnum = vlen;
	edgenum = elen;

	for (int i = 0; i < vlen; i++){
		this->vexs[i].data = vexs[i];
		// this->vexs[i].firstEdge = nullptr;
	}

	for (int i = 0 ; i < elen ; i++){
		char c1 = edges[i][0];
		char c2 = edges[i][1];

		int p1 = getPosition(c1);
		int p2 = getPosition(c2);

		node1 = new Enode();
		node1->ivex = p2;

		if(this->vexs[p1].firstEdge == nullptr){
			this->vexs[p1].firstEdge = node1;
		}else{
			linkLast(this->vexs[p1].firstEdge,node1);
		}

		node2 = new Enode();
		node2->ivex = p1;
		if(this->vexs[p2].firstEdge == nullptr){
			this->vexs[p2].firstEdge = node2;
		}else{
			linkLast(this->vexs[p2].firstEdge,node2);
		}
	}
}

LinkUDG::~LinkUDG(){

}
void LinkUDG::print(){
	for (int i = 0; i < vexnum;i++){
		cout<<i<<"("<<vexs[i].data<<"):";
		Enode* node = vexs[i].firstEdge;
		while(node){
			cout<<node->ivex<<"("<<vexs[node->ivex].data<<")";
			node = node->nextEdge;
		}
		cout<<endl;
	}
}

int LinkUDG::getPosition(char ch){
	for (int i = 0; i < vexnum; i++){
		if(vexs[i].data == ch){
			return i;
		}
	}
	return -1;
}

char LinkUDG::getChar(){
	char ch;
	do{
		cin>>ch;
	}while(!((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')));
	return ch;
}

void LinkUDG::linkLast(Enode* link,Enode* node){
	Enode* p = link;
	while(p->nextEdge){
		p = p->nextEdge;
	}
	p->nextEdge = node;
}
#endif