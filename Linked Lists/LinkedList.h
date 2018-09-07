#pragma once
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList {
	public:
		LinkedList();
		LinkedList(const LinkedList& list);
		~LinkedList();

		void addFirst(T data);
		void addLast(T data);
		void deleteFirst();
		void deleteLast();
		bool isEmpty();
		T get(int pos);
		bool change(int fPos, int sPos);
		T set(T data, int pos);
		void print();
		/*Hw 5*/
		void reverse();
		bool operator ==(const LinkedList<T> &list);
		void operator +=(T dato);
		void operator += (const LinkedList<T> &list);
		void operator =(const LinkedList<T> &list);

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
/*Copy constructor []*/
template<class T>
LinkedList<T>::LinkedList(const LinkedList& list) {
	this->size = list.size;
	if (list.head != NULL) {
		Node<T> *curr1 = list.head;
		head = new Node<T>(curr1->getData());
		Node<T> *curr2 = head;
		curr1 = curr1->getNext();
		while (curr1 != NULL) {
			curr2->setNext(new Node<T>(curr1->getData()));
			curr1 = curr1->getNext();
			curr2 = curr2->getNext();
		}
		
	}
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
T LinkedList<T>::set(T data, int pos) {
	Node<T> *curr = head;
	for (int i = 0; i < pos; i++) {
		curr = curr->getNext();
	}
	T dataAux = curr->getData();
	curr->setData(data);
	return dataAux;
}
template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
	if (pos1 == pos2) {
		return true;
	}
	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);
	Node<T> *curr1 = head;
	for (int i = 1; i <= posMen; i++){
		curr1 = curr1->getNext();
	}
	Node<T> *curr2 = curr1;
	for (int i = posMen; i < posMay; i++) {
		curr2 = curr2->getNext();
	}
	T dataAux = curr1->getData();
	curr1->setData(curr2->getData());
	curr2->setData(dataAux);

	return true;
}
template <class T>
void LinkedList<T>::print() {
	Node<T> *curr = head;
	while (curr != NULL) {
		cout << curr->getData() << " ";
		curr = curr->getNext();
	}
	cout << endl;
}
/*reverse []*/
template <class T>
void LinkedList<T>::reverse() {
	Node<T> *curr1 = head;
	Node<T> *prev = NULL;

	curr1 = head->getNext();
	head->setNext(NULL);
	prev = head;
	while (curr1 != NULL) {
		head = curr1;
		curr1 = curr1->getNext();	
		head->setNext(prev);
		prev = head;
	}
}
/*Operator == []*/
template <class T>
bool LinkedList<T>::operator == (const LinkedList<T> &list) {
	int i = 0;
	if (this->size != list.size) {
		return false;
	}
	else {
		Node<T> *curr1 = this->head;
		Node<T> *curr2 = list.head;

		for (i = 0; i < this->size; i++) {
			if (curr1->getData() != curr2->getData()) {
				return false;
			}
			curr1 = curr1->getNext();
			curr2 = curr2->getNext();
		}
		return true;
	}
}
/*Operator +=(T dato) []*/
template <class T>
void LinkedList<T>::operator+=(T dato) {
	addLast(dato);
}
/*Operator += (LinkedList list) []*/
template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &list) {
	Node<T> *curr1 = head;
	Node<T> *curr2 = list.head;
	//Recorre toda la lista hasta llegar a nulo
	while (curr1->getNext() != NULL) {
		curr1 = curr1->getNext();
	}
	//Recorre toda la lista 2 y crea nodos al final de la lista 1 y aumenta el tamano
	while (curr2 != NULL) {
		curr1->setNext(new Node<T>(curr2->getData()));
		curr1 = curr1->getNext();
		curr2 = curr2->getNext();
		size++;
	}

}
/*Operator =[]*/
template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &list) {
	deleteAll();
	this->size = list.size;
	if (list.head != NULL) {
		Node<T> *curr1 = list.head;
		head = new Node<T>(curr1->getData());
		Node<T> *curr2 = head;
		curr1 = curr1->getNext();
		while (curr1 != NULL) {
			curr2->setNext(new Node<T>(curr1->getData()));
			curr1 = curr1->getNext();
			curr2 = curr2->getNext();
		}

	}
}