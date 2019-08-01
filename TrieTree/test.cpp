#include <iostream>
#include "header.h"

using namespace std;

int main() {
	Trie* t = new Trie();
	t->insert("abc");
	t->insert("a");
	// t->insert("vbh");
	if (t->find("a")) {
		cout<<"exits";
	}

	return 0;
}

