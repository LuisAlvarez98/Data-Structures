/*
	by Luis Felipe Alvarez Sanchez
*/
#include <vector>
#include <iostream>
using namespace std;
class Priority {
	public:
		Priority();
		Priority(bool priority);
		void push(int data);
		void pop();
		int top();
		int size();
		bool empty();
		void print();
	private:
		vector<int>heap;
		bool priority;
		bool compare(int x, int y);
		void swap(int &x, int  &y);
};
Priority::Priority() {
	priority = true;
}
Priority::Priority(bool priority) {
	this->priority = priority;
}
int Priority::top() {
	return heap[0];
}
void Priority::pop() {
	int i;
	int size = heap.size() - 1;
	swap(heap[0], heap[size - 1]);
	heap.pop_back();
	size--;
	for (i = 0; i<(heap.size() - 1) / 2; i++){
		if (!compare(heap[(i + 1) * 2], heap[(i + 1) * 2 - 1])) {
			if (compare(heap[i], heap[(i + 1) * 2])) {
				swap(heap[i], heap[(i + 1) * 2]);
			}
		}
		else {
			if (compare(heap[i], heap[(i + 1) * 2 - 1])) {
				swap(heap[i], heap[(i + 1) * 2 - 1]);
			}
		}
	}
}
void Priority::push(int data) {
	heap.push_back(data);
	int count = heap.size() - 1;
	while (heap.size() >= 0 && compare(heap[count], heap[count / 2])) {
		swap(heap[count], heap[count / 2]);
		count /= 2;
	}
}
bool Priority::empty() {
	return heap.size() == 0;
}
void Priority::swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
bool Priority::compare(int x, int y) {
	return priority ? x < y : x > y;
}
int Priority::size() {
	return heap.size();
}
void Priority::print() {
	int i;
	for (i = 0; i < heap.size(); i++) {
		cout << heap[i] << " ";
	}
}