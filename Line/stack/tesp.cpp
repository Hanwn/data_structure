#include <iostream>
#include "header.h"
using namespace std;

int main(){
	myStack s = myStack();
	for (int i = 0 ; i < 10; i++){
		s.push(i);
	}
	s.display();
	for(int j = 0 ; j < 10 ; j++){
		cout<<s.pop();
	}
	return 0;
}