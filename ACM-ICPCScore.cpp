#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>   
/*
	ACM ICPC
	By Luis Felipe Alvarez Sanchez
	A01194173
	20 Aug 2018
*/
using namespace std;
struct Reg {
	//Variables
	string name;
	char wrongProblems[100];
	int counter = 0;
	int acc = 0;
	int timeTotal = 0;
	//Getters and setters
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return this->name; 
	}
	int getTime() {
		return this->timeTotal;
	}
	int getAcc() {
		return this->acc;
	}
	//Operator > overload
	friend bool operator>(Reg r1, Reg r2) {
		if (r1.getAcc() > r2.getAcc())
		{
			return false;
		}
		else if (r1.getAcc() == r2.getAcc())
		{
			if (r1.getTime() < r2.getTime())
			{
				return false;
			}
		}
		return true;
	}
	//Correct problems manager method
	void addJudgementCounter(char j, char problem, int time) {
		int wrongCounter = 0;
		switch (j) {
		case 'A':
			for (int i = 0; i < counter; i++) {
				if (problem == wrongProblems[i]) {
					wrongCounter++;
				}
			}
			timeTotal += 20 * wrongCounter;
			timeTotal = time + timeTotal;
			acc++;
			break;
		case 'W':
			wrongProblems[counter] = problem;
			counter++;
			break;
		}
	}
};
//Swap elements method
void changeMethod(Reg *teamOne, Reg *teamTwo) {
	Reg aux = *teamOne;
	*teamOne = *teamTwo;
	*teamTwo = aux;
}
//Bubble sort method
void sort(Reg teams[], int size){
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++) {
			if (teams[j] > teams[j + 1]) {
				changeMethod(&teams[j], &teams[j + 1]);
			}
		}
}
//Print leaderboard method
void printLeaderBoard(Reg teams[], int size)
{
	for (int o = 0; o < size; o++) {
		if (teams[o].getTime() == 0) {
			cout << o + 1 << " - " << teams[o].getName() << " " << teams[o].getAcc() << " " << "-" << "\n";
		}
		else {
			cout << o + 1 << " - " << teams[o].getName() << " " << teams[o].getAcc() << " " << teams[o].getTime() << "\n";
		}
	}
}
//Main method
int main()
{
	//Variables
	Reg eq[20];
	int i, j, k;
	bool flagT = true, flagT2 = true, flagT3 = true;
	int iTime, numOfTeams, numOfProblems, numOfSolutions;
	string iEquipo;
	char iProblem, iJudgement;
	string teamName;

	//Asks for num of teams
	while (flagT) {
		cin >> numOfTeams;
		((numOfTeams >= 1 && numOfTeams <= 20)) ? (flagT = false) : (flagT = true);
	}
	//Asks for num of problems
	while (flagT2) {
		cin >> numOfProblems;
		((numOfProblems >= 1 && numOfProblems <= 10)) ? (flagT2 = false) : (flagT2 = true);
	}
	//Asks for team names
	for (i = 0; i < numOfTeams; i++) {
		cin >> teamName;
		eq[i].setName(teamName);
	}
	//Asks for number of solutions
	while (flagT3) {
		cin >> numOfSolutions;
		((numOfSolutions >= 1 && numOfSolutions <= 1000)) ? (flagT3 = false) : (flagT3 = true);
	}
	//Input solutions
	for (j = 0; j < numOfSolutions; j++) {
			cin >> iEquipo >> iProblem >> iTime >> iJudgement;
				for (k = 0; k < numOfTeams; k++) {
				if (iEquipo == eq[k].getName()) {
					eq[k].addJudgementCounter(iJudgement, iProblem , iTime);
				}
		}
	}
	//Sort and print teams
	sort(eq, numOfTeams);
	printLeaderBoard(eq, numOfTeams);
    return 0;
}

