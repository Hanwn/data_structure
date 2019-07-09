#include <iostream>

using namespace std;

struct Node{
	Node(int val):data(val),lchild(nullptr),rchild(nullptr),parent(nullptr){};
	int data;
	Node* lchild;
	Node* rchild;
	Node* parent;
};

class BSTree{
public:
	BSTree();
	~BSTree();
public:
	// CRUD
	void insert(int val);
	Node* find_iterator(int val);
	Node* find_recursive(int val);
	int find_max();
	int find_min();
	void remove(int val);

public:
	void preOrder();
	void inOrder();
	void postOrder();
	void layerOrder();
private:
	Node* find(Node* root,int val);
	Node* predecessor(Node* p);
	void destroy(Node* p);
	void preOrder(Node* p);
	void inOrder(Node* p);
	void postOrder(Node* p);
	void layerOrder(Node* p);
	void remove(Node* p,int val);


private:
	Node* root;
};

BSTree::BSTree():root(nullptr){

}

BSTree::~BSTree(){
	destroy(root);
}


//增
void BSTree::insert(int val){
	// pparent用来记录插入位置的父节点，类似于链表中pre的作用
	Node* pparent = nullptr;
	Node* pnode = root;
	while(pnode){
		pparent = pnode;
		if(val > pnode->data){
			pnode = pnode->rchild;
		}else if(val < pnode->data){
			pnode = pnode->lchild;
		}else{
			break;
		}
	}
	pnode = new Node(val);
	if(!pparent){
		root = pnode;
	}else{
		if(val > pparent->data){
			pparent->rchild = pnode;
		}else{
			pparent->lchild = pnode;
		}
	}
	pnode->parent = pparent;
}

// 查

//迭代进行查找
Node* BSTree::find_iterator(int val){
	Node* pnode = root;
	while(pnode){
		if(val > pnode->data){
			pnode = pnode->rchild;
		}else if(val < pnode->data){
			pnode = pnode->lchild;
		}else{
			return pnode;
		}
	}
	return nullptr;
}

// 递归进查找
Node* BSTree::find_recursive(int val){
	return find(root,val);
}
Node* BSTree::find(Node* root,int val){
	if(!root){
		return nullptr;
	}else if(val<root->data){
		return find(root->lchild,val);
	}else if(val>root->data){
		return find(root->rchild,val);
	}else{
		return root;
	}
}

int BSTree::find_max(){
	Node* p = root;
	while(p->rchild){
		p = p->rchild;
	}
	return p->data;
}

int BSTree::find_min(){
	Node* p = root;
	while(p->lchild){
		p = p->lchild;
	}
	return p->data;
}

void BSTree::preOrder(){
	preOrder(root);
}
void BSTree::preOrder(Node* p){
	if(p){
		cout<<p->data<<"->";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
void BSTree::inOrder(){
	inOrder(root);
}
void BSTree::inOrder(Node* p){
	if(p){
		inOrder(p->lchild);
		cout<<p->data<<"->";
		inOrder(p->rchild);
	}
}

void BSTree::postOrder(){
	postOrder(root);
}
void BSTree::postOrder(Node* p){
	if(p){
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout<<p->data<<"->";
	}
}

// 删

// 析构函数
void BSTree::destroy(Node* p){
	if(p){
		if(p->lchild){
			destroy(p->lchild);
		}
		if(p->rchild){
			destroy(p->rchild);
		}
		delete p;
		p = nullptr;
	}
}


// 删除指定节点

/*
总结一下关于二叉搜索树的删除操作

1.首先找到要删除的节点(pdel),分为两种情况,有两个子树的和没有两个子树的
2.然后找到删除节点的孩子(child)节点(这个时候已经保证了被删除节点只存在一棵子树或者没有子树的情况)
但是要注意,如果pdel删除的是根节点,则直接root赋地址为child
3.如果child存在,则让pdel->parent = child->parent,使child单向连接
4.再将pdel->parent->lchild/rchild = child;进行单项连接,从而将pdel架空
5.如果删除的节点的值不等于要删除的值,则将删除节点的值覆盖到原来要删除的值的地方.

*/


// 删除指定节点，有三种情况
// 1.叶子节点
// 2.只有右结点
// 3.只有左节点
// 4.存在左右节点
void BSTree::remove(int val){
	remove(root,val);
}
void BSTree::remove(Node* p,int val){
	if(p){
		if(p->data == val){
			Node* pdel = nullptr;
			// 情况1，2，3
			if(!p->lchild||!p->rchild){
				pdel = p;
			}else{
				// 情况4
				// 先把该节点的前驱节点的值覆盖本节点的值，然后删除该节点的前驱节点
				pdel = predecessor(p);
			}
			Node* child = nullptr;
			if(pdel->lchild){
				// 被删除的节点存在左节点的情况
				child = pdel->lchild;
			}else{
				// 被删除的节点，不存在左节点的情况下
				child = pdel->rchild;
			}

			if(child){
				// 对应情况2，3，4，即存在节点的情况下
				child->parent = pdel->parent;
			}
			// 如果删除的是节点是根节点
			if(!pdel->parent){
				// 让root指向左子树
				root = child;
			// 如果要删除的节点不是根节点，且被删除节点作为左节点
			}else if(pdel->parent->lchild == pdel){
				pdel->parent->lchild = child;
			}else{
				pdel->parent->rchild = child;
			}
			if(p->data != pdel->data){
				p->data = pdel->data;
			}
			delete pdel;

		}else if(val > p->data){
			remove(p->rchild,val);
		}else{
			remove(p->lchild,val);
		}
	}
}


// 寻找前驱节点，有三种情况
// 1.存在左子树
// 2.不存在左子树,且本身为右子树,则前驱节点为其父节点
// 3.不存在左子树,且本身为左子树,则前驱节点为第一个拥有右子树的父节点
Node* BSTree::predecessor(Node* p){
	if(p->lchild){
		p = p->lchild;
		while(p->rchild){
			p = p->rchild;
		}
		return p;
	}

	Node* pparent = p->parent;
	while(pparent&&pparent->lchild == p){
		p = pparent;
		pparent = pparent->parent;
	}
	return pparent;
}


