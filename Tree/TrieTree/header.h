#include <iostream>
#include <cstring>
using namespace std;

const int branch_num = 26; 

#ifndef _HEADER_H_

#define _HEADER_H_
struct Node{
	bool is_str;
	Node* branch[branch_num];
};

class Trie{
public:
	Trie();
	~Trie();
public:
	void insert(const char *word);
	bool find(const char *word);
private:
	void del(Node* p);
private:
	Node* root;	
};

Trie::Trie() {
	root = new Node();
	root->is_str = false;
	for (int i = 0 ; i < branch_num; i++) {
		root->branch[i] = nullptr;
	}
}

Trie::~Trie () {
	del(root);
}

void Trie::insert(const char *word) {
	Node* p = root;
	while (*word) {
		if (p->branch[*word - 'a'] == nullptr) {
			Node* insert_node = new Node();
			insert_node->is_str = false;
			for (int i = 0; i < branch_num; i++) {
				insert_node->branch[i] = nullptr;
			}
			p->branch[*word - 'a'] = insert_node;
		}
		p = p->branch[*word - 'a'];
		word++;
	}
	p->is_str = true;
}

void Trie::del (Node* p) {
	for (int i = 0; i < branch_num; i++) {
		if (p->branch[i]) {
			del(p->branch[i]);
		}
	}
	delete p;
}

bool Trie::find (const char* word) {
	Node* p = root;
	while(*word&&p) {
		p = p->branch[*word - 'a'];
		word++;
	}
	return (p&&p->is_str);
}



#endif