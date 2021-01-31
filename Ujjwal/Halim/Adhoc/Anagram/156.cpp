#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define s second

/*
 * Learned :- STL transform function
 */

// Just Group the word according to the input given and then check if the group contains single word
// Complexity is O(nLogn) Space :- O(N)

int main () {
	string str;
	while(cin >> str) {
		map<string, vector<string>> m;
		while(1) {
			
			if(str == "#") break;
			string temp = str;
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower); // to transform whole string to lowercase
			sort(temp.begin(), temp.end());
			m[temp].push_back(str);
			cin >> str;
		}
		
		vector<string> ans;
		for(auto p : m) {
			if((int)p.s.size() == 1) ans.push_back(p.s[0]);
		}
		sort(ans.begin(), ans.end());
		for(string s : ans) {
			puts(s.c_str());
		}
	}
	return 0;
} 
