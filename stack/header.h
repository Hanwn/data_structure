
#include <iostream>

using namespace std;

struct Node{
	Node(int val):data(val),next(nullptr){};
	int data;
	Node* next;
};

class myStack{
public:
	myStack():length(0),head(new Node(-1)){};
	~myStack();
public:
	void push(int val);
	int top();
	int pop();
	bool isEmpty();
	void display();
private:
	int length;
	Node* head;

};

myStack::~myStack(){
	while(head){
		Node* p = head;
		head = head->next;
		delete p;
	}
	this->length = 0;
}

void myStack::push(int val){

	Node* p = new Node(val);
	p->next = head->next;
	head->next = p;
	this->length++;
}

int myStack::top(){
	if(isEmpty()){
		return INT_MIN;
	}
	return head->next->data;
}

int myStack::pop(){
	if (isEmpty())
	{
		return INT_MIN;
	}
	Node* p = head->next;
	head->next = p->next;
	int pop_data = p->data;
	delete p;
	this->length--;
	return pop_data;
}

bool myStack::isEmpty(){
	return length==0;
}

void myStack::display(){
	Node* p = head->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
}