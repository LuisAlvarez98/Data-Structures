// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"LinkedList.h"
#include <iostream>
using namespace std;
int main()
{
	LinkedList<int> list;
	list.addFirst(5);
	list.add(5,1);
	list.add(6, 2);
	cout << list.getSize() << "\n";
    return 0;
}

