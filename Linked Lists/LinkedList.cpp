// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"LinkedList.h"
#include <vector>
int main()
{
	//Lineal no Cuadratico
	LinkedList<int> l1;
	l1.addFirst(8);
	l1.add(40, 1);
	l1.add(5, 2);
	l1.add(20, 3);
	l1.addLast(25);
	
	l1.print();
	l1.reverse();
	l1.print();
	l1.reverse();
	l1.print();
    return 0;
}

