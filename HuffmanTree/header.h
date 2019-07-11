#include <iostream>
#include "MinHeap.h"

using namespace std;


class Huffman{
public:
	Huffman():root(nullptr){};
	~Huffman();
public:
	void create(int a[],int size);
	void preOrder();
	void inOrder();
	void postOrder();
private:
	void preOrder(Node* p);
	void inOrder(Node *p);
	void postOrder(Node *p);
	void destroy();
	void destroy(Node* p);
private:
	Node* root;
};

Huffman::~Huffman(){
	destroy();
}

void Huffman::create(int a[],int size){
	Node* left,*right,*parent;
	MinHeap* heap = new MinHeap();
	heap->create(a,size);
	// 这里需要注意的是：遍历的末尾是size-1，因为需要size - 1取出，即构建的huffman树有size-1个非叶节点
	for(int i = 0; i < size - 1 ;i++){
		left = heap->get_min();
		right = heap->get_min();
		parent = new Node(left->data + right->data,left,right,nullptr);
		left->parent = parent;
		right->parent = parent;

		if(heap->copyof(parent)){
			cout<<"failed"<<endl;
			destroy(parent);
			parent = nullptr;
			break;
		}

	}

	root = parent;
	heap->destroy();
	delete heap;
}

void Huffman::preOrder(){
	preOrder(root);
}

void Huffman::preOrder(Node* p){
	if(p){
		cout<<p->data<<" ";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

void Huffman::inOrder(){
	inOrder(root);
}

void Huffman::inOrder(Node* p){
	if(p){
		inOrder(p->lchild);
		cout<<p->data<<" ";
		inOrder(p->rchild);
	}
}

void Huffman::postOrder(){
	postOrder(root);
}

void Huffman::postOrder(Node* p){
	if(p){
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout<<p->data<<" ";
	}
}

void Huffman::destroy(){
	destroy(root);
}
void Huffman::destroy(Node* p){
	if(p){
		destroy(p->lchild);
		destroy(p->rchild);
		delete p;
	}
}