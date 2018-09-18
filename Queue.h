#pragma once
#include "Node.h"
template <class T>
class Queue {
	public:
		Queue();
		~Queue();

		T front();
		void push(T data);
		void pop();
		int size();
		bool empty();

	private:
		Node<T> *ultimo;
		int tam;
};
template <class T>
Queue<T>::Queue() {
	ultimo = NULL;
	tam = 0;
}
template <class T>
Queue<T>::~Queue() {
	if (ultimo != NULL) {
		Node<T> * curr = ultimo->getNext();
		ultimo->setNext(NULL);
		ultimo = curr;
		while (ultimo != NULL) {
			ultimo = ultimo->getNext();
			delete curr;
			curr = ultimo;
		}
	}
}
template <class T>
T Queue<T>::front() {
	return ultimo->getNext()->getData();
}
template <class T>
void Queue<T>::push(T data) {
	if (ultimo == NULL) {
		ultimo = new Node<T>(data);
		ultimo->setNext(ultimo);
	}
	else {
		ultimo->setNext(new Node<T>(data, ultimo->getNext()));
		ultimo = ultimo->getNext();
	}
	tam++;
}
template <class T>
void Queue<T>::pop() {
	Node<T> *curr = ultimo->getNext();
	if (ultimo->getNext() == ultimo) {
		ultimo = NULL;
	}
	else {
		ultimo->setNext(curr->getNext());
	}
	delete curr;
	tam--;
}
template <class T>
int Queue<T>::size() {
	return tam;
}
template <class T>
bool Queue<T>::empty() {
	return ultimo == NULL;
}