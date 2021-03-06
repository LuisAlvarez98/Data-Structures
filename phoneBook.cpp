#include "stdafx.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
	map<string, string> phonebook;
	vector<string> results;
	string query, name, number;
	int nQueries, i, j;

	cin >> nQueries;
	for ( j = 0; j < nQueries; j++) {
		cin >> query;
		if (query == "add") {
			cin >> number >> name;
			phonebook[number] = name;
		}
		else if (query == "del") {
			cin >> number;
			phonebook.erase(number);
		}
		else if (query == "find") {
			cin >> number;
			map<string, string>::iterator itfind = phonebook.find(number);
			if (itfind != phonebook.end()) {
				results.push_back(itfind->second);
			}
			else {
				results.push_back("not found");
			}
		}
	}
	for (i = 0; i < results.size(); i++) {
		cout << results[i] << "\n";
	}
    return 0;
}