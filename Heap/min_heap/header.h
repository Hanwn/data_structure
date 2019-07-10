#include <iostream>

using namespace std;

class MinHeap
{
public:
	MinHeap(int val);
	~MinHeap();
public:
	bool insert(int val);
	bool remove(int val);
	void print();
	int getMin();
private:
	void filterup(int index);
	void filterdown(int begin,int end);
private:
	int capacity;
	int size;
	int* heap;
};

MinHeap::MinHeap(int val){
	capacity = val;
	size = 0;
	heap = new int[capacity];
}
MinHeap::~MinHeap(){
	delete[] heap;
}

bool MinHeap::insert(int val){
	if(size == capacity){
		return false;
	}
	heap[size] = val;
	filterup(size);
	size++;
	return true;
}
bool MinHeap::remove(int val){
	if(!size){
		return false;
	}
	int index = 0;
	for (; index < size; index++){
		if(heap[index] == val){
			break;
		}
	}
	if(index == size){
		return false;
	}
	heap[index] = heap[size - 1];
	filterdown(index,size--);
	return true;

}

/*
总结一下最小堆的删除操作
*/

void MinHeap::filterdown(int begin,int end){
	int childIndex = begin * 2 + 1;
	int val = heap[begin];
	while(begin<=end){
		if(childIndex < end && heap[childIndex] > heap[childIndex]){
			childIndex++;
		}
		if(val < heap[childIndex]){
			break;
		}else{
			heap[begin] = heap[childIndex];
			begin = childIndex;
			childIndex = childIndex * 2 + 1;
		}
	}
	heap[begin] = val;
}

/*
总结一下最小堆的插入操作

*/

void MinHeap::filterup(int index){
	int val = heap[index];
	while(index){
		int parentIndex = (index - 1)/2;
		if(heap[parentIndex] <= heap[index]){
			break;
		}else{
			heap[index] = heap[parentIndex];
			index = parentIndex;
		}
	}
	heap[index] = val;
}

void MinHeap::print(){
	for (int i = 0; i < size; i++){
		cout<<heap[i]<<" ";
	}
}

int MinHeap::getMin(){
	if(size){
		return heap[0];
	}
	return INT_MIN;
}