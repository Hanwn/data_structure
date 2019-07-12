#include <iostream>

using namespace std;

class Base{
public:
	Base(int val){};
};

class Derived{
public:
	Derived():b(Base(5)){};
private:
	Base b;

};

int main(){

	Derived d = Derived();

	return 0;
}