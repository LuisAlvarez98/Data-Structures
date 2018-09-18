#pragma once
#include "Node.h"

template <class T>
class Stack {
	public:
		Stack();
		~Stack();

		T top();
		void push(T data);
		void pop();
		int size();
		bool empty();

	private:
		Node<T> *tope;
		int tam;
};
//Constructor
template <class T>
Stack<T>::Stack() {
	tope = NULL;
	tam = 0;
}
//Destructor
template <class T>
Stack<T>::~Stack() {
	Node<T> *curr = tope;
	while (tope != NULL) {
		tope = tope->getNext();
		delete curr;
		curr = tope;
	}
}
//Top, returns top element
template <class T>
T Stack<T>::top() {
	return tope->getData();
}
//Size, returns the stacks size
template <class T>
int Stack<T>::size() {
	return tam;
}
//Empty, checks if the stack is empty
template <class T>
bool Stack<T>::empty() {
	return tope == NULL;
}
//Push, adds element to the top
template <class T>
void Stack<T>::push(T data) {
	tope = new Node<T>(data, tope);
	tam++;
}
//Pop, removes elements from the top
template <class T>
void Stack<T>::pop() {
	Node<T> *curr = tope;
	tope = tope->getNext();
	delete curr;
	tam--;
}