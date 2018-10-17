#pragma once
#include "NodeT.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class BST
{
  public:
	BST();
	BST(const BST &cpy);
	~BST();
	void add(int data);
	bool search(int data);
	void ancestors(int data);
	void remove(int data);
	void print(int c);
	int maxWidth();
	void printLeaves();
	int getCount();
	int height();
	int whatLevelAmI(int data);
	bool operator==(const BST &bTree);
	bool compare(NodeT *t1, NodeT *t2);
	void mirror();
	int nearestRelative(int a, int b);

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
	void leaves(NodeT *r);
	int getHeight(NodeT *r);
	int count(NodeT *r);
	void getMirror(NodeT *r);
	void copy(NodeT *t1, NodeT *t2);
};
//Constructor
BST::BST()
{
	root = NULL;
}
//Copy constructor
BST::BST(const BST &cpy)
{
	root = new NodeT(cpy.root->getData());
	copy(this->root, cpy.root);
}
void BST::copy(NodeT *t1, NodeT *t2)
{
	if (t2 != NULL)
	{
		if (t2->getLeft() != NULL)
		{
			t1->setLeft(new NodeT(t2->getLeft()->getData()));
			copy(t1->getLeft(), t2->getLeft());
		}
		if (t2->getRight() != NULL)
		{
			t1->setRight(new NodeT(t2->getRight()->getData()));
			copy(t1->getRight(), t2->getRight());
		}
	}
}
//Destructor
BST::~BST()
{
	liberar(root);
}
int BST::getCount()
{
	return count(root);
}
int BST::count(NodeT *r)
{
	if (r == NULL)
	{
		return 0;
	}
	return 1 + count(r->getLeft()) + count(r->getRight());
}
//Prints Leaves
void BST::printLeaves()
{
	leaves(root);
	cout << endl;
}
//Prints Leaves
void BST::leaves(NodeT *r)
{
	if (!r)
	{
		return;
	}
	if (r->getLeft() == NULL && r->getRight() == NULL)
	{
		cout << r->getData() << " ";
	}
	if (r->getLeft())
	{
		leaves(r->getLeft());
	}
	if (r->getRight())
	{
		leaves(r->getRight());
	}
}
int BST::howManyChildren(NodeT *r)
{
	int c = 0;
	if (r->getLeft() != NULL)
	{
		c++;
	}
	if (r->getRight() != NULL)
	{
		c++;
	}
	return c;
}
bool BST::search(int data)
{
	NodeT *curr = root;
	while (curr != NULL)
	{
		if (curr->getData() == data)
		{
			return true;
		}
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;
}
int BST::pred(NodeT *r)
{
	//Mas grande de los chicos
	NodeT *aux = r->getLeft();
	while (aux->getRight() != NULL)
	{
		aux = aux->getRight();
	}
	return aux->getData();
}
int BST::succ(NodeT *r)
{
	//Mas chicos de los grandes
	NodeT *aux = r->getRight();
	while (aux->getLeft() != NULL)
	{
		aux = aux->getLeft();
	}
	return aux->getData();
}
//Hacer clon de arbol
void BST::preOrder(NodeT *r)
{
	if (r != NULL)
	{
		cout << r->getData() << " ";
		preOrder(r->getLeft());
		preOrder(r->getRight());
	}
}

void BST::inOrder(NodeT *r)
{
	if (r != NULL)
	{
		inOrder(r->getLeft());
		cout << r->getData() << " ";
		inOrder(r->getRight());
	}
}
//se usa para borrar
void BST::postOrder(NodeT *r)
{
	if (r != NULL)
	{
		postOrder(r->getLeft());
		postOrder(r->getRight());
		cout << r->getData() << " ";
	}
}
void BST::liberar(NodeT *r)
{
	if (r != NULL)
	{
		liberar(r->getLeft());
		liberar(r->getRight());
		delete r;
	}
}
void BST::add(int data)
{
	NodeT *father = NULL;
	NodeT *curr = root;
	while (curr != NULL)
	{
		//No duplicates
		if (curr->getData() == data)
		{
			return;
		}
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	//If empty
	if (father == NULL)
	{
		root = new NodeT(data);
	}
	else
	{
		if (father->getData() > data)
		{
			father->setLeft(new NodeT(data));
		}
		else
		{
			father->setRight(new NodeT(data));
		}
	}
}
void BST::remove(int data)
{
	NodeT *curr = root;
	NodeT *father = NULL;
	while (curr != NULL && curr->getData() != data)
	{
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == NULL)
	{
		return;
	}
	int c = howManyChildren(curr);
	switch (c)
	{
	case 0:
		if (father == NULL)
		{
			root = NULL;
		}
		else
		{
			if (father->getData() > data)
			{
				father->setLeft(NULL);
			}
			else
			{
				father->setRight(NULL);
			}
		}
		delete curr;
		break;
	case 1:
		if (father == NULL)
		{
			if (curr->getLeft() != NULL)
			{
				root = curr->getLeft();
			}
			else
			{
				root = curr->getRight();
			}
		}
		else
		{
			if (father->getData() > data)
			{
				if (curr->getLeft() != NULL)
				{
					father->setLeft(curr->getLeft());
				}
				else
				{
					father->setRight(curr->getRight());
				}
			}
			else
			{
				if (curr->getLeft() != NULL)
				{
					father->setRight(curr->getLeft());
				}
				else
				{
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
int BST::whatLevelAmI(int data)
{
	NodeT *curr = root;
	int level = 0;
	while (curr != NULL)
	{
		if (curr->getData() == data)
		{
			return level;
		}
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		level++;
	}
	return -1;
}
//ANCESTORS
void BST::ancestors(int data)
{
	NodeT *curr = root;
	stack<int> ancestor;
	while (curr != NULL)
	{
		if (curr->getData() == data)
		{
			while (!ancestor.empty())
			{
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
int BST::height()
{
	return getHeight(root);
}
//HEIGHT
int BST::getHeight(NodeT *r)
{
	if (r == NULL)
	{
		return 0;
	}
	int izq = getHeight(r->getLeft());
	int der = getHeight(r->getRight());
	return 1 + (izq > der ? izq : der);
}
//Nivel x Nivel
void BST::breadthFirstSearch()
{
	NodeT *curr = root;
	queue<NodeT *> q;
	q.push(curr);
	while (!q.empty())
	{
		cout << q.front()->getData() << " ";
		if (q.front()->getLeft() != NULL)
		{
			q.push(q.front()->getLeft());
		}
		if (q.front()->getRight() != NULL)
		{
			q.push(q.front()->getRight());
		}
		q.pop();
	}
}
//nearestRelative done
int BST::nearestRelative(int a, int b)
{
	NodeT *curr1 = root;
	NodeT *curr2 = root;
	queue<int> r1;
	bool f1 = false, f2 = false;
	int nR;

	while (!f1)
	{
		if (curr1->getData() == a)
		{
			f1 = true;
		}
		r1.push(curr1->getData());
		curr1 = (curr1->getData() > a) ? curr1->getLeft() : curr1->getRight();
	}
	while (!f2)
	{
		if (curr2->getData() == b)
		{
			f2 = true;
		}
		if (curr2->getData() == r1.front())
		{
			nR = r1.front();
			r1.pop();
		}
		curr2 = (curr2->getData() > b) ? curr2->getLeft() : curr2->getRight();
	}
	return nR;
}
//maxWidth done
int BST::maxWidth()
{
	NodeT *curr = root;
	if (curr == NULL)
	{
		return 0;
	}
	int maxWidth = 0;
	queue<NodeT *> q;
	q.push(curr);
	while (!q.empty())
	{
		int qSize = q.size();
		maxWidth = max(qSize, maxWidth);
		while (qSize != 0)
		{
			if (q.front()->getLeft() != NULL)
			{
				q.push(q.front()->getLeft());
			}
			if (q.front()->getRight() != NULL)
			{
				q.push(q.front()->getRight());
			}
			qSize--;
			q.pop();
		}
	}
	return maxWidth;
}
// Operator == done
bool BST::operator==(const BST &bTree)
{
	NodeT *tree1 = this->root;
	NodeT *tree2 = bTree.root;
	if (tree1 == NULL && tree2 == NULL)
	{
		return true;
	}
	else if (tree1 == NULL || tree2 == NULL)
	{
		return false;
	}
	else
	{

		return compare(tree1, tree2);
	}
}
bool BST::compare(NodeT *t1, NodeT *t2)
{
	if (t1 != NULL || t2 != NULL)
	{
		if (t1->getData() == t2->getData())
		{
			return compare(t1->getLeft(), t2->getLeft()) && compare(t1->getRight(), t2->getRight());
		}
		else
		{
			return false;
		}
	}
}
//Mirror done
void BST::mirror()
{
	getMirror(root);
}
void BST::getMirror(NodeT *r)
{
	NodeT *temp;
	if (r != NULL)
	{
		//Recorre el arbol de forma recursiva
		if (r->getLeft() != NULL)
		{
			getMirror(r->getLeft());
		}
		if (r->getRight() != NULL)
		{
			getMirror(r->getRight());
		}
		temp = r->getLeft();
		r->setLeft(r->getRight());
		r->setRight(temp);
	}
}
void BST::print(int c)
{
	switch (c)
	{
	case 1:
		preOrder(root);
		break;
	case 2:
		inOrder(root);
		break;
	case 3:
		postOrder(root);
		break;
	case 4:
		printLeaves();
		break;
	case 5:
		breadthFirstSearch();
		break;
	}
	cout << endl;
}