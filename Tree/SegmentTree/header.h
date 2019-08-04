#include <iostream>
#include <vector>
using namespace std;

#ifndef _HEADER_H_
#define _HEADER_H_

struct TreeNode{
	TreeNode(int start,int end):left(nullptr),right(nullptr){
		this->start = start;
		this->end = end;
		sum = 0;
	}
	int start,end;
	int sum;
	TreeNode* left;
	TreeNode* right;
};
class SegmentTree{
public:
	SegmentTree(vector<int>& v);
	~SegmentTree();
public:
	TreeNode* build(vector<int>& v,int s,int e);
	void update(int i,int val);
	void print();
	int sumRange(int s,int e);
private:
	void update(TreeNode* p,int i,int val);
	void del(TreeNode* p);
	void print(TreeNode* p);
	int sumRange(TreeNode* p,int s,int e);
private:
	TreeNode* root;
	int s;
	int e;
};

SegmentTree::SegmentTree(vector<int>& v) {
	int s = 0;
	int e = v.size() - 1;
	root = build(v,s,e);
}
SegmentTree::~SegmentTree() {
	del(root);
}

TreeNode* SegmentTree::build(vector<int>& v,int s,int e) {
	if (s > e) {
		return nullptr;
	}
	TreeNode* p = new TreeNode(s,e);
	if (s == e) {
		p->sum = v[s];
	} else {
		int mid = s + (e - s)/2;
		p->left = build(v,s,mid);
		p->right = build(v,mid + 1,e);
		p->sum = p->left->sum + p->right->sum;
	}
	return p;
}

void SegmentTree::del(TreeNode* p) {
	if (p) {
		del(p->left);
		del(p->right);
		delete p;
	}
}

void SegmentTree::update(int i,int val) {
	update(root,i,val);
}

void SegmentTree::update(TreeNode* p,int i,int val) {
	if (p->start == p->end) {
		p->sum = val;
	} else {
		int mid = p->start + (p->end - p->start)/2;
		if (i <= mid) {
			update(p->left,i,val);
		} else {
			update(p->right,i,val);
		}
		p->sum = p->left->sum + p->right->sum;
	}
}

void SegmentTree::print() {
	print(root);
}

int SegmentTree::sumRange(int s,int e) {
	int res = sumRange(root,s,e);
	cout<<endl;
	cout<<"sumRange("<<s<<","<<e<<"):"<<res<<endl;
	return res;
}

int SegmentTree::sumRange(TreeNode* p,int s,int e) {
	if (p->start == s && p->end == e) {
		return p->sum;
	}
	int mid = p->start + (p->end - p->start)/2;
	if (mid >= e) {
		return sumRange(p->left,s,e);
	} else if (mid < s) {
		return sumRange(p->right,s,e);
	}else {
		return sumRange(p->left,s,mid) + sumRange(p->right,mid + 1,e);
	}

}

void SegmentTree::print(TreeNode* p) {
	if (p) {
		cout<<"|"<<p->start<<" "<<p->end<<" "<<p->sum<<" ";
		print(p->left);
		print(p->right);	
	}
}
#endif