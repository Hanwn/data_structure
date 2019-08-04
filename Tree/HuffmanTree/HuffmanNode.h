#ifndef _HUFFMAN_NODE_
#define _HUFFMAN_NODE_

struct Node{
	Node(){};
	Node(int val, Node* L,Node* R,Node* P):data(val),lchild(L),rchild(R),parent(P){};
	int data;
	Node* lchild;
	Node* rchild;
	Node* parent;
};
#endif