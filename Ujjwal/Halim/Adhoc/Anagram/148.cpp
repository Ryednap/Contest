#include <bits/stdc++.h>
using namespace std;

// Unable to solve maximum complexity reached is O(n!).

int main() {
	string str;
	while( cin >> str ) {
		vector<string> dict;
		while(1) {
			if(str == "#") break;
			sort(str.begin(), str.end());
			dict.push_back(str);
			cin >> str;
		}
		
		while(1) {
			if(str == "#") break;
			string input = "";
			stringstream p(str);
			string temp;
			while(p >> temp) {
				input += temp;
			}
			sort(temp.begin(), temp.end());
			
		}
