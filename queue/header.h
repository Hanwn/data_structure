#include <iostream>

using namespace std;

struct Node{
	Node(int val):data(val),next(nullptr){}
	int data;
	Node* next;
};

class myQueue{
public:
	myQueue():length(0),head(new Node(-1)),rail(head){};
	~myQueue();
public:
	void push(int val);
	int pop();
	bool isEmpty();
	void display();
private:
	int length;
	Node* head;
	Node* rail;
};

myQueue::~myQueue(){
	while(head!=rail){
		Node* p = head;
		head = head->next;
		delete p;
	}
	delete head;
}

void myQueue::push(int val){
	Node* p = new Node(val);
	rail->next = p;
	rail = p;
}

int myQueue::pop(){
	if(isEmpty()){
		return INT_MIN;
	}
	Node* p = head->next;
	head = p->next;
	int pop_data = p->data;
	this->length--;
	delete p;
	return pop_data;
}
bool myQueue::isEmpty(){
	return length==0;
}

void myQueue::display(){
	Node* p = head->next;
	while(p){
		cout<<p->data<<"|";
		p = p->next;
	}
}