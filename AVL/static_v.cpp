#include <iostream>

using namespace std;

class Demo
{
public:
	static int a;
};

int Demo::a = 10;

int main(){
	Demo d = Demo();
	d.a = 15;
	cout<<d.a;
	Demo x = Demo();
	cout<<x.a;
	return 0;
}