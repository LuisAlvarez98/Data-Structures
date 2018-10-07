#pragma once
#include "NodeT.h"
#include <iostream>
using namespace std;
class BST {
	public:
		BST();
		~BST();
		void add(int data);
		bool search(int data);
		void remove(int data);
		void print(int c);
	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int pred(NodeT *r);
		int succ(NodeT *r);
		void preOrder(NodeT *r);
		void inOrder(NodeT *r);
		void postOrder(NodeT *r);
		void liberar(NodeT *r);
};
BST::BST() {
	root = NULL;
}
BST::~BST() {
	liberar(root);
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
void BST::print(int c) {
	switch (c) {
	case 1: preOrder(root);
		break;
	case 2: inOrder(root);
		break;
	case 3: postOrder(root);
		break;
	}
	cout << endl;
}