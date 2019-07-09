#include <iostream>

using namespace std;

struct Node{
	Node(int val):data(val),height(0),lchild(nullptr),rchild(nullptr){};
	int data;
	int height;
	Node* lchild;
	Node* rchild;
};

class AVLTree{
public:
	AVLTree();
	~AVLTree();
public:
	void insert(int val){

	}
private:
	Node* root;
};	