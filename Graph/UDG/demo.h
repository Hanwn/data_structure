#include<iostream>

using namespace std;

class Base{
public:
	Base():i(5){};
private:
	int i;
	// char nums[i];这种做法是不对的！
};

int main(){
	Base b = Base();
	return 0;
}
