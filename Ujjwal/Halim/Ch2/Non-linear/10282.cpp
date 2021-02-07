#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


// Level 1 problem 

// Missed some time because of not-reading the message format

// 1 min 11 sec for thinking
// 5 min 23 sec for coding
// 2 min 51 sec for debugin

int main() {
	string str;
	map<string, string> mapper;
	while (getline(cin , str) ) {
		if(str == "") break;
		stringstream ss(str);
		string eng, foreign;
		ss >> eng >> foreign;
		mapper[foreign] = eng;
	}
	
	//debug() << owo(mapper);
	
	string s;
	while ( cin >> s) {
		if(mapper.find(s) != mapper.end()) {
			puts (mapper[s].c_str());
		} else {
			puts("eh");
		}
	}
	
	return 0;
}


