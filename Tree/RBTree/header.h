

#ifndef _RBTreeHeader_
#define _RBTreeHeader_
#include <iostream>
#include <iomanip>
using namespace std;

enum RBTColor{
	RED,BLACK
};

struct Node{
	RBTColor color;
	int key;
	Node* left;
	Node* right;
	Node* parent;
	Node(int val,RBTColor c,Node* l,Node* r,Node* p) {
		key = val,color = c,left = l,right = r,parent = nullptr;
	}
};

class RBTree{
private:
	Node* mRoot;
public:
	RBTree(){};
	~RBTree();

public:
	void insert(int key);
	void remove(int key);
	Node* search(int key);
	void print();
private:
	void insert(Node* &root,Node* node);
	void remove(Node* &root,Node* node);
	void removeFixup(Node* &root,Node* node,Node* parent);
	void insertFixup(Node* &root,Node* node);
	void leftRotate(Node* &root,Node* node);
	void rightRotate(Node* &root,Node* node);
	Node* search(Node* root,int key);
	void print(Node* tree,int key,int direction);
	void destroy();
	void destroy(Node* &root);

};
RBTree::~RBTree() {
	destroy();
}
void RBTree::insert(int key) {
	Node* z = nullptr;

	z = new Node(key,BLACK,nullptr,nullptr,nullptr);
	insert(mRoot,z);
}
void RBTree::insert(Node* &root,Node* node) {
	Node* y = nullptr;
	Node* x = root;
	while (x) {
		y = x;
		if (node->key < x->key) {
			x = x->left;
		}else{
			x = x->right;
		}
	}
	node->parent = y;
	if (y != nullptr) {
		if (node->key < y-> key) {
			y->left = node;
		}else{
			y->right = node;
		}
	}else{
		root = node;
	}
	node->color = RED;
	insertFixup(root,node);
}



void RBTree::insertFixup(Node* &root,Node* node) {
	Node* parent = nullptr,*gparent = nullptr;
	while((parent = node->parent) && (parent->color == RED)) {
		gparent = parent->parent;
		//当前节点的父节点是祖父节点的左孩子
		if (parent == gparent->left) {
			Node* uncle = gparent->right;
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
				continue;
			}

			if (parent->right == node) {
				Node* tmp;
				leftRotate(root,parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			parent->color = BLACK;
			gparent->color = RED;
			rightRotate(root,gparent);


		}else{

			Node* uncle = gparent->left;
			if (uncle && uncle->color == RED) {
				uncle->color = BLACK;
				parent->color = BLACK;
				gparent->color = RED;
				node = gparent;
				continue;
			}

			if (parent->left == node) {
				Node* tmp;
				rightRotate(root,parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			parent->color = BLACK;
			gparent->color = RED;
			leftRotate(root,gparent);

		}
	}
	root->color = BLACK;
}


void RBTree::leftRotate(Node* &root,Node* node) {
	Node* y = node->right;
	node->right = y->left;
	if (y->left) {
		y->left->parent = node;
	}
	y->parent = node->parent;
	if (node->parent == nullptr) {
		root = y;
	}else{
		if (node->parent->left == node) {
			node->parent->left = y;
		}else{
			node->parent->right = y;
		}
	}
	y->left = node;
	node->parent = y;
}
void RBTree::rightRotate(Node* &root,Node* node) {
	Node* y = node->left;
	node->left = y->right;
	if (y->right) {
		y->right->parent = node;
	}
	y->parent = node->parent;
	if (node->parent == nullptr) {
		root = y;
	}else{
		if (node->parent->left == node) {
			node->parent->left = y;
		}else{
			node->parent->right = y;
		}
	}
	y->right = node;
	node->parent = y;
}

void RBTree::remove(int key) {
	Node* node = search(mRoot,key);
	if (node != nullptr) {
		remove(mRoot,node);
	}
}


/*
#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
*/

void RBTree::remove(Node* & root,Node* node) {
	Node* child,*parent;
	RBTColor color;
	if ((node->left) && (node->right)) {
		Node* replace = node;

		replace = replace->right;
		while (replace->left) {
			replace = replace->left;
		}

		if (node->parent) {
			if (node->parent->left == node) {
				node->parent->left = replace;
			}else{
				node->parent->right = replace;
			}
		}else{
			root = replace;
		}
		child = replace->right;
		parent = replace->parent;
		color = replace->color;

		if (parent == node) {
			parent = replace;
		}else{
			if (child) {
				child->parent = parent;
			}
			parent->left = child;
			replace->right = node->right;
			node->right->parent = replace;
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->left = node->left;
		node->left->parent = replace;

		if (color == BLACK) {
			removeFixup(root,child,parent);
		}
		delete node;
		return;
	}
	if (node->left) {
		child = node->left;
	}else{
		child = node->right;
	}
	parent = node->parent;
	color = node->color;

	if (child) {
		child->parent = parent;
	}
	if (parent) {
		if (parent->left == node) {
			parent->left =  child;
		}else{
			parent->right = child;
		}
	}else{
		root = child;
	}
	if (color == BLACK) {
		removeFixup(root,child,parent);
	}
	delete node;
}



void RBTree::removeFixup(Node* &root,Node* node,Node* parent) {
	Node* other;
	while ((!node || node->color == BLACK) && node != root) {
		if (parent->left == node) {
			other = parent->right;
			if (other->color == RED) {
				//case1.node的兄弟节点other是红色的
				other->color = BLACK;
				parent->color = RED;
				leftRotate(root,parent);
				other = parent->right;
			}
			if ((!other->left || other->left->color == BLACK) && (!other->right || other->right->color == BLACK)) {
				//case2 node的兄弟节点other是黑色，并且other的两个儿子节点也是黑色
				other->color = RED;
				node = parent;
				parent = node->parent;
			}else{
				if (!other->right || other->right->color == BLACK) {
					//case3 node的兄弟节点other是黑色的，并且other的左孩子是红色	，右孩子是黑色
					other->left->color = BLACK;
					other->color = RED;
					rightRotate(root,other);
					other = parent->right;
				}

				//case4 node的兄弟节点other是黑色的，并且other的右孩子节点是红色，左孩子任意颜色
				other->color = parent->color;
				parent->color = BLACK;
				other->right->color = BLACK;
				leftRotate(root,parent);
				node = root;
				break;
			}
		}else{
			other = parent->left;
			if (other->color == RED) {
				//case1
				other->color = BLACK;
				parent->color = RED;
				rightRotate(root,parent);
				other = parent->left;
			}
			if ((!other->left || other->left->color == BLACK) && (!other->right || other->right->color == BLACK)) {
				//case2
				other->color = RED;
				node = parent;
				parent = node->parent;
			}else{
				if (!other->left || other->left->color == BLACK) {
					//case3
					other->left->color = BLACK;
					other->color = RED;
					leftRotate(root,other);
					other = parent->right;
				}
				//case4
				other->color = parent->color;
				parent->color = BLACK;
				other->right->color = BLACK;
				leftRotate(root,parent);
				node = root;
				break;
			}
		}
	}
	if (node) {
		node->color = BLACK;
	}
}

void RBTree::destroy() {
	destroy(mRoot);
}
void RBTree::destroy(Node* &tree) {
	if (tree == nullptr) return;
	if (tree->left) destroy(tree->left);
	if (tree->right) destroy(tree->right);
	delete tree;
	tree = nullptr;
}

Node* RBTree::search(Node* root,int key) {
	if (root == nullptr || root->key == key) return root;
	if (key < root->key) return search(root->left,key);
	else return search(root->right,key);
}
void RBTree::print(Node* tree,int key,int direction) {
	if (tree) {
		if (direction == 0) {
			cout<<setw(2)<<tree->key<<"(B) is root" << endl;
		}else{
			cout<<setw(2)<<tree->key<< ((tree->color == RED)?"(R)":"(B)") << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;
		}
		print(tree->left,tree->key,-1);
		print(tree->right,tree->key,1);
	}
}
void RBTree::print() {
	if (mRoot) {
		print(mRoot,mRoot->key,0);
	}
}


#endif