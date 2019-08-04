#include <iostream>

using namespace std;

class MaxHeap{
public:
	MaxHeap(int cap);
	~MaxHeap();
public:
	bool insert(int val);
	bool remove(int val);
	void print();
	int getMax();

private:
	int capacity;
	int size;
	int* heap;
private:
	void filterup(int index);
	void filterdown(int begin,int end);
};
MaxHeap::MaxHeap(int cap){
	capacity = cap;
	size = 0;
	heap = new int[cap];
}

MaxHeap::~MaxHeap(){
	delete[] heap;
}

void MaxHeap::print(){
	for (int i = 0; i < size; i++){
		cout<<heap[i]<<" ";
	}
}
int MaxHeap::getMax(){
	if(size){
		return heap[0];
	}
	return INT_MIN;
}

bool MaxHeap::insert(int val){
	if(size == capacity){
		return false;
	}
	heap[size] = val;
	filterup(size);
	size++;
	return true;
}
bool MaxHeap::remove(int val){
	if(!size){
		return false;
	}
	int index;
	for (index = 0; index < size; index++){
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

void MaxHeap::filterdown(int begin,int end){
	int childIndex = begin * 2 + 1;

	int val = heap[begin];
	while(childIndex <= end){
		if(childIndex < end && heap[childIndex] < heap[childIndex + 1]){
			childIndex++;
		}
		if(val > heap[childIndex]){
			break;
		}else{
			heap[begin] = heap[childIndex];
			begin = childIndex;
			childIndex = childIndex * 2 + 1;
		}
	}
	heap[begin] = val;
}
void MaxHeap::filterup(int index){
	int val = heap[index];
	while(index){
		int parentIndex = (index - 1)/2;
		if(val < heap[parentIndex]){
			break;
		}else{
			heap[index] = heap[parentIndex];
			index = parentIndex;
		}
	}
	heap[index] = val;
}