#include <iostream>

using namespace std;

struct Node{
	Node(int val,Node* L,Node* R):data(val),height(0),lchild(L),rchild(R){};
	int data;
	int height;
	Node* lchild;
	Node* rchild;
};

class AVLTree{
public:
	AVLTree():root(nullptr){};
	~AVLTree();
public:
	// CRUD
	void insert(int val);
	void remove(int val);
	int find_max();
	int find_min();

	int height();

	void preOrder();

	int max(int a,int b);


private:
	Node* ll_rotation(Node* p);
	Node* rr_rotation(Node* p);
	Node* lr_rotation(Node* p);
	Node* rl_rotation(Node* p);
	Node* insert(Node* p,int val);
	Node* remove(Node* p,int val);
	Node* find_max(Node* p);
	Node* find_min(Node* p);
	void destroy();
	void destroy(Node* p);
	void preOrder(Node* p);
	int height(Node* p);
private:
	Node* root;
};

AVLTree::~AVLTree(){
	destroy();
}


void AVLTree::insert(int val){
	root = insert(root,val);
}

/*
AVLTree插入操作与BSTree的不同：
*/

Node* AVLTree::insert(Node* p,int val){
	if(!p){
		p = new Node(val,nullptr,nullptr);
	}else if(val > p->data){
		p->rchild = insert(p->rchild,val);

		if(height(p->rchild) - height(p->lchild) == 2){
			if(val > p->rchild->data){
				p = rr_rotation(p);
			}else if(val < p->rchild->data){
				p = rl_rotation(p);
			}
		}
	}else if(val < p->data){
		p->lchild = insert(p->lchild,val);
		if(height(p->lchild) - height(p->rchild) == 2){
			if(val > p->lchild->data){
				p = lr_rotation(p);
			}else if(val < p->lchild->data){
				p = ll_rotation(p);
			}
		}
	}
	p->height = max(height(p->lchild),height(p->rchild)) + 1;
	return p;
}

void AVLTree::remove(int val){
	remove(root,val);
}
Node* AVLTree::remove(Node* p,int val){
	if (p){
		if(val == p->data){
			// 如果左右子树都不为空
			if(p->lchild&&p->rchild){
				if(height(p->lchild) > height(p->lchild)){
					Node* p_max = find_max(p->lchild);
					p->data = p_max->data;
					// 这里需要注意：要递归删除
					remove(p->lchild,p_max->data);
				}else{
					Node* p_min = find_min(p->rchild);
					p->data = p_min->data;
					remove(p->rchild,p_min->data);
				}
			}else{
			// 有一个为空或者两个都为空
				Node* pdel = p;
				if(p->lchild){
					p = p->lchild;
				}else if (p->rchild){
					p = p->rchild;
				}
				delete pdel;
				return p;
			}
		}else if(val > p->data){
			p->rchild = remove(p->rchild,val);
			if(height(p->lchild) - height(p->rchild) == 2){
				if(height(p->lchild->lchild) > height(p->lchild->rchild)){
					p = ll_rotation(p);
				}else{
					p = lr_rotation(p);
				}
			}
		}else if(val < p->data){
			p->lchild = remove(p->lchild,val);
			if(height(p->rchild) - height(p->lchild) == 2){
				if(height(p->rchild->lchild) > height(p->rchild->rchild)){
					p = rl_rotation(p);
				}else{
					p = rr_rotation(p);
				}
			}
		}
		return p;
	}
	return nullptr;

}


int AVLTree::max(int a,int b){
	return a>b?a:b;
}

int AVLTree::height(){
	return height(root);
}

int AVLTree::height(Node* p){
	if(p){
		return p->height;
	}
	return 0;
}

int AVLTree::find_max(){
	Node* p = find_max(root);
	if(p){
		return p->data;
	}else{
		return INT_MAX;
	}

}

int AVLTree::find_min(){
	Node* p = find_min(root);
	if(p){
		return p->data;
	}else{
		return INT_MIN;
	}
}

Node* AVLTree::find_max(Node* p){
	if(p){
		while(p->rchild){
			p = p->rchild;
		}
		return p;
	}
	return p;
}
Node* AVLTree::find_min(Node* p){
	if(p){
		while(p->lchild){
			p = p->lchild;
		}
		return p;
	}
	return p;
}

Node* AVLTree::ll_rotation(Node* p){
	Node* new_p = p->lchild;
	p->lchild = new_p->rchild;
	new_p->rchild = p;

	p->height = max(height(p->lchild),height(p->rchild)) + 1;
	new_p->height = max(height(new_p->lchild),height(new_p->rchild)) + 1;

	return new_p;
}
Node* AVLTree::rr_rotation(Node* p){
	Node* new_p = p->rchild;
	p->rchild = new_p->lchild;
	new_p->lchild = p;

	p->height = max(height(p->lchild),height(p->rchild)) + 1;
	new_p->height = max(height(new_p->lchild),height(new_p->rchild)) + 1;


	return new_p;
}
Node* AVLTree::lr_rotation(Node* p){
	p->lchild = rr_rotation(p->lchild);
	return ll_rotation(p);
}
Node* AVLTree::rl_rotation(Node* p){
	p->rchild = ll_rotation(p);
	return rr_rotation(p);
}

void AVLTree::preOrder(){
	preOrder(root);
}

void AVLTree::preOrder(Node* p){
	if(p){
		cout<<p->data<<endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

void AVLTree::destroy(){
	destroy(root);
}
void AVLTree::destroy(Node* p){
	if(p){
		destroy(p->lchild);
		destroy(p->rchild);
		delete p;
	}
}
