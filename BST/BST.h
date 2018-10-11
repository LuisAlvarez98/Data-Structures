#pragma once
#include "NodeT.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class BST {
	public:
		BST();
		~BST();
		void add(int data);
		bool search(int data);
		void ancestors(int data);
		void remove(int data);
		void print(int c);
		//t
		void printLeaves();
		int getCount();
		int height();
		int whatLevelAmI(int data);

	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int pred(NodeT *r);
		int succ(NodeT *r);
		void preOrder(NodeT *r);
		void breadthFirstSearch();
		void inOrder(NodeT *r);
		void postOrder(NodeT *r);
		void liberar(NodeT *r);
		//t
		void leaves(NodeT *r);
		int getHeight(NodeT *r);
		int count(NodeT *r);
};
BST::BST() {
	root = NULL;
}
BST::~BST() {
	liberar(root);
}
//Count nodes
int BST::getCount() {
	return count(root);
}
int BST::count(NodeT *r) {
	int counter = 1;
	if (!r) {
		return 0;
	}
	else {
		counter += count(r->getLeft());
		counter += count(r->getRight());
		return counter;
	}
}
//Prints Leaves
void BST::printLeaves() {
	leaves(root);
	cout << endl;
}
//Prints Leaves
void BST::leaves(NodeT *r) {
	if (!r) {
		return;
	}
	if (r->getLeft() == NULL && r->getRight() == NULL) {
		cout << r->getData() << " ";
	}
	if (r->getLeft()) {
		leaves(r->getLeft());
	}
	if (r->getRight()) {
		leaves(r->getRight());
	}
}
int BST::howManyChildren(NodeT *r) {
	int c = 0;
	if (r->getLeft() != NULL) {
		c++;
	}
	if (r->getRight() != NULL) {
		c++;
	}
	return c;
}
bool BST::search(int data) {
	NodeT *curr = root;
	while (curr != NULL) {
		if (curr->getData() == data) {
			return true;
		}
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;
}
int BST::pred(NodeT *r) {
	//Mas grande de los chicos
	NodeT *aux = r->getLeft();
	while (aux->getRight() != NULL) {
		aux = aux->getRight();
	}
	return aux->getData();
}
int BST::succ(NodeT *r) {
	//Mas chicos de los grandes
	NodeT *aux = r->getRight();
	while (aux->getLeft() != NULL) {
		aux = aux->getLeft();
	}
	return aux->getData();
}
//Hacer clon de arbol
void BST::preOrder(NodeT *r) {
	if (r != NULL) {
		cout << r->getData() << " ";
		preOrder(r->getLeft());
		preOrder(r->getRight());
	}
}

void BST::inOrder(NodeT *r) {
	if (r != NULL) {
		inOrder(r->getLeft());
		cout << r->getData() << " ";
		inOrder(r->getRight());
	}
}
//se usa para borrar
void BST::postOrder(NodeT *r) {
	if (r != NULL) {
		postOrder(r->getLeft());
		postOrder(r->getRight());
		cout << r->getData() << " ";
	}
}
void BST::liberar(NodeT *r) {
	if (r != NULL) {
		liberar(r->getLeft());
		liberar(r->getRight());
		delete r;
	}
}
void BST::add(int data) {
	NodeT *father = NULL;
	NodeT *curr = root;
	while (curr != NULL) {
		//No duplicates
		if (curr->getData() == data) {
			return;
		}
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	//If empty
	if (father == NULL) {
		root = new NodeT(data);
	}
	else {
		if (father->getData() > data) {
			father->setLeft(new NodeT(data));
		}
		else {
			father->setRight(new NodeT(data));
		}
	}
}
void BST::remove(int data) {
	NodeT *curr = root;
	NodeT *father = NULL;
	while (curr != NULL && curr->getData() != data) {
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == NULL) {
		return;
	}
	int c = howManyChildren(curr);
	switch (c) {
		case 0:
			if (father == NULL) {
				root = NULL;
			}
			else {
				if (father->getData() > data) {
					father->setLeft(NULL);
				}
				else {
					father->setRight(NULL);
				}
			}
			delete curr;
			break;
		case 1:
			if (father == NULL) {
				if (curr->getLeft() != NULL) {
					root = curr->getLeft();
				}
				else {
					root = curr->getRight();
				}
			}
			else {
				if (father->getData() > data) {
					if (curr->getLeft() != NULL) {
						father->setLeft(curr->getLeft());
					}
					else {
						father->setRight(curr->getRight());
					}
				}
				else {
					if (curr->getLeft() != NULL) {
						father->setRight(curr->getLeft());
					}
					else {
						father->setRight(curr->getRight());
					}
				}
			}
			delete curr;
			break;
		case 2:
			int x = succ(curr);
			remove(x);
			curr->setData(x);
			break;
	}
}
//WhatLevelAmI
int BST::whatLevelAmI(int data) {
	NodeT *curr = root;
	int level = 0;
	while (curr != NULL) {
		if (curr->getData() == data) {
			return level;
		}
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		level++;
	}
	return -1;
}
//ANCESTORS
void BST::ancestors(int data) {
	NodeT *curr = root;
	stack<int>ancestor;
	while (curr != NULL) {
		if (curr->getData() == data) {
			while (!ancestor.empty()) {
				cout << ancestor.top() << " ";
				ancestor.pop();
			}
			return;
		}
		ancestor.push(curr->getData());
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
}
//HEIGHT
int BST::height() {
	return getHeight(root);
}
//HEIGHT
int BST::getHeight(NodeT *r) {
	if (r == NULL) {
		return 0;
	}
	else {
		if (r->getLeft() == NULL && r->getRight() == NULL) {
			return 1;
		}
		else {
			return 1 + max(getHeight(r->getLeft()), getHeight(r->getRight()));
		}
	}
}
//Nivel x Nivel
void BST::breadthFirstSearch() {
	NodeT *curr = root;
	queue<NodeT*> q;
	q.push(curr);
	while (!q.empty()) {
		cout << q.front()->getData() << " ";
		if (q.front()->getLeft() != NULL) {
			q.push(q.front()->getLeft());
		}
		if (q.front()->getRight() != NULL) {
			q.push(q.front()->getRight());
		}
		q.pop();
	}
}
void BST::print(int c) {
	switch (c) {
	case 1: preOrder(root);
		break;
	case 2: inOrder(root);
		break;
	case 3: postOrder(root);
		break;
	case 5:
		breadthFirstSearch();
		break;
	}
	cout << endl;
}