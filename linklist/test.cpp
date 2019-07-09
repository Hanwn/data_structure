#include "header.h"
#include <iostream>

using namespace std;

int main(){
	linkList l = linkList();

	for(int i = 0; i < 10 ; i++){
		l.insert_head(i);
	}
	l.display();
	return 0;
}