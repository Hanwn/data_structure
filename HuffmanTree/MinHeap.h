#include <iostream>
#include "HuffmanNode.h"

#ifndef _MIN_HEAP_
#define _MIN_HEAP_

class MinHeap
{
public:
	MinHeap(){};
	~MinHeap();
public:
	void create(int arr[],int size);
	int copyof(Node* p);
	Node* get_min();
	void destroy();
private:
	void filterUp(int index);
	void filterDown(int begin,int end);
	void swap(int i,int j);
	
private:
	Node* heap;
	int capacity;
	int size;
	
};

MinHeap::~MinHeap(){
	destroy();
}

int MinHeap::copyof(Node* p){
	if(size == capacity){
		return -1;
	}
	heap[size] = *p;
	filterUp(size);
	size++;
	return 0;
}

Node* MinHeap::get_min(){
	if(!size){
		return nullptr;
	}
	Node* node = &heap[0];
	swap(0,size-1);
	filterDown(0,size-2);
	size--;
	return node;
}

void MinHeap::swap(int i,int j){
	Node temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void MinHeap::filterDown(int begin,int end){
	Node val = heap[begin];
	while(begin<=end){
		int child = 2 * begin + 1;
		if(child < end&&heap[child].data > heap[child + 1].data){
			child++;
		}
		if(heap[child].data >= val.data){
			break;
		}else{
			heap[child] = heap[begin];
			begin = child;
		}
	}
	heap[begin] = val;
}

void MinHeap::filterUp(int index){
	Node val = heap[index];
	while(index){
		int parentIndex = (index-1)/2;
		if(heap[parentIndex].data>=val.data){
			break;
		}else{
			heap[index] = heap[parentIndex];
			index = parentIndex;
		}
	}
	heap[index] = val;
}

void MinHeap::create(int arr[],int size){
	this->size = size;
	capacity = size;
	heap = new Node[size];
	int i = 0;
	for ( ; i < size; i++){
		heap[i].data = arr[i];
		heap[i].parent = heap[i].lchild = heap[i].rchild = nullptr;
	}
	for(i = size/2 - 1 ; i>=0 ; i--){
		filterDown(i,size-1);
	}
}



void MinHeap::destroy(){
	delete heap;
	size = 0;
	heap = nullptr;
}
#endif