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
	bool create(int arr[],int size);
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

bool MinHeap::create(int arr[],int size){
	if(capacity<size){
		return false;
	}
	for(int i = 0; i < size; i++){
		insert(arr[i]);
	}
	return true;
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
1.要注意，这里的begin实际上就相当于在filterup中的index；
2.从上往下，势必有两个比较对象，对于最小堆而言，只要将较小的那个值与父节点进行比较即可；
3.更新父节点，同时更新父节点指针、孩子指针；
4.最后用原数据覆盖begin位置的数据
*/

void MinHeap::filterdown(int begin,int end){
	// int childIndex = begin * 2 + 1;
	int val = heap[begin];
	while(begin < end){
		int childIndex = begin * 2 + 1;
		if(childIndex < end && heap[childIndex] > heap[childIndex]){
			childIndex++;
		}
		if(val < heap[childIndex]){
			break;
		}else{
			heap[begin] = heap[childIndex];
			begin = childIndex;
			// childIndex = childIndex * 2 + 1;
		}
	}
	heap[begin] = val;
}

/*
总结一下最小堆的插入操作：
1.每次插入的值都在最后一个位置，所以首先要将最后一个节点的值保存起来；
2.对于每次一个节点的父节点，如果比它小，则不需要进行，已经满足了最小堆的条件
3.如果比它大，则要用父节点的值覆盖子节点的值（子节点的值已经被保护起来了），父节点的位置给子节点，到上一个层级比较

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