#include "stdafx.h"
#include <sstream>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include<functional>
using namespace std;

stack<int> sp;
queue<int> que;
priority_queue<int, vector<int>, greater<int> > priorQue;


int calOperator(int x, int y, string oper) {
	if (oper == "+") {
		return x + y;
	}
	else if(oper == "-") {
		return y - x;
	}
	else if (oper == "*") {
		return x * y;
	}
	else {
		return 0;
	}
}

void stackOperation(string oper) {
	int x, y, sol;

	x = sp.top();
	sp.pop();
	y = sp.top();
	sp.pop();
	sol = calOperator(x, y, oper);
	sp.push(sol);
}
void queueOperation(string oper) {
	int x, y, sol;
	x = que.front();
	que.pop();
	y = que.front();
	que.pop();
	sol = calOperator(x, y,oper);
	que.push(sol);
}
void priorQueueOperation(string oper) {
	int x, y, sol;
	x = priorQue.top();
	priorQue.pop();
	y = priorQue.top();
	priorQue.pop();
	sol = calOperator(x, y, oper);
	priorQue.push(sol);
}
int main()
{
	//Reads the strings
	string d, data;

	getline(cin, data);
	while (data != "#") {
		stringstream ss;
		ss << data;
		while (ss >> d) {
			if (d == "+" || d == "-" || d == "*") {
				//Starts stack operation
				stackOperation(d);
				//Starts queue operation
				queueOperation(d);
				//Starts priority queue operation
				priorQueueOperation(d);
			}
			else {
				//add numbers to stack;
				sp.push(stoi(d));
				//add numbers to queue;
				que.push(stoi(d));
				//add numbers to priority queue;
				priorQue.push(stoi(d));
			}
		}
		cout << sp.top() << " " << que.front() << " " << priorQue.top() << "\n";
		sp.pop();
		que.pop();
		priorQue.pop();
		getline(cin, data);
	}
    return 0;
}

