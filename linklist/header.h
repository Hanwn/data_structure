#include <iostream>
using namespace std;
struct Node{
	Node():data(-1),next(NULL){};
	Node(int val):data(val),next(NULL){};
	int data;
	Node* next;
};

class linkList{
public:
	linkList():length(0),head(new Node()){};
	~linkList();
public:
	// CRUD
	void insert_rail(int val);
	void insert_head(int val);

	bool isEmpty();
	int size();

	void display();

private:
	int length;
	Node* head;
};

linkList::~linkList(){
	while(head){
		Node* p = head;
		head = head->next;
		delete p;
	}
}

void linkList::insert_head(int val){
	Node* p = new Node(val);
	p->next = head->next;
	head->next = p;
	this->length++;
}

void linkList::insert_rail(int val){
	Node* p = new Node(val);
	Node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = p;
	this->length++;
}

void linkList::display(){
	Node* p = head->next;
	while(p){
		cout<<p->data;
		if(p->next){
			cout<<"->";
		}
		p = p->next;
	}
}

bool linkList::isEmpty(){
	return length==0;
}
int linkList::size(){
	return length;
}