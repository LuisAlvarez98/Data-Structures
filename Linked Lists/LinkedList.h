#pragma once
#include "Node.h"

template <class T>
class LinkedList {
	public:
		LinkedList();
		~LinkedList();

		void addFirst(T data);
		void addLast(T data);
		void deleteFirst();
		void deleteLast();
		bool isEmpty();

		int getSize();
		bool add(T data, int pos);
		void del(int pos);
		int deleteAll();
	private:
		Node<T> *head;
		int size;
		void deleteHelper();
};
template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}
template <class T>
LinkedList<T>::~LinkedList() {
	deleteHelper();
}
template <class T>
void LinkedList<T>::addFirst(T data) {
	head = new Node<T>(data, head);
	size++;
}
template <class T>
void LinkedList<T>::addLast(T data) {
	if (this->isEmpty()) {
		addFirst(data);
	}
	else {
		Node<T> *curr = head;
		while (curr->getNext() != NULL) {
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data));
		size++;
	}
}
template <class T>
void LinkedList<T>::deleteFirst() {
	if (!this->isEmpty()) {
		Node<T> *curr = head;
		head = head->getNext();
		delete curr;
		size--;
	}
}
template <class T>
void LinkedList<T>::deleteLast() {
	if (size <= 1) {
		deleteFirst();
	}
	else {
		Node<T> *curr = head;
		while (curr->getNext()->getNext() != NULL) {
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(NULL);
		size--;
	}
}
template <class T>
int LinkedList<T>::getSize() {
	return this->size;
}
//Checar
template <class T>
bool LinkedList<T>::add(T data, int pos) {
	if (pos > size) {
		return false;
	}
	if (pos == 0) {
		addFirst(data);
	}
	else if (pos == size) {
		addLast(data);
	}
	else {
		Node<T> *curr = head;
		for (int i = 1; i < pos; i++) {
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data, curr->getNext()));
		size++;
	}
	return true;
}
template <class T>
void LinkedList<T>::del(int pos) {
	if (pos == 0) {
		deleteFirst();
	}
	else if (pos == size - 1) {
		deleteLast();
	}
	else {
		Node<T> *curr = head;
		for (int i = 1; i < pos; i++) {
			curr = curr->getNext();
		}
		Node<T> *temp = curr->getNext();
		curr->setNext(temp->getNext());
		delete temp;
		size--;
	}
}

template<class T >
int LinkedList<T>::deleteAll() {
	int cant = size;
	deleteHelper();
	size = 0;
	return cant;
}
template <class T>
void LinkedList<T>::deleteHelper() {
	Node<T> *curr = head;
	while (head != NULL) {
		head = head->getNext();
		delete curr;
		curr = head;
	}
}
template <class T>
bool LinkedList<T>::isEmpty() {
	return (head == NULL);
	//return (size == 0);
}
template <class T>
T LinkedList<T>::get(int pos) {
	int i;
	if (this->isEmpty() || pos < 0 || pos > size) {
		return NULL;
	}
	else {
		Node<T>*curr = head;
		for (i = 0; i < pos; i++) {
			curr = curr->getNext();
		}
		return curr->getData();
	}
}
template <class T>
T LinkedList<T>::set(T new_data, int pos) {
	int k;
	if (!isEmpty() && pos < size && pos >= 0) {
		Node<T> *curr = head;
		for (k = 1; k < pos; k++) {
			curr = curr->getNext();
		}
		//Guarda info anterior
		Node<T> *aux = new Node<T>(curr->getData());
		//Setea el dato nuevo e
		curr->setData(new_data);
		//Regresa info anterior
		return aux->getData();
	}
}
template <class T>
bool LinkedList<T>::change(int fPos, int sPos) {
	Node<T> *one = head;
	Node<T> *two = head;
	int i, j;
	if (isEmpty() || fPos > size || sPos > size || fPos < 0 || sPos < 0) {
		return false;
	}
	else if (fPos == sPos) {
		return false;
	}
	else {
		for (i = 0; i < fPos; i++) {
			one = one->getNext();
		}
		for (j = 0; j < sPos; j++) {
			two = two->getNext();
		}
		//changes position
		Node<T> *aux = new Node<T>(one->getData());
		//Sets two on one
		one->setData(two->getData());
		//Sets one on two
		two->setData(aux->getData());
	}
	return true;
}
