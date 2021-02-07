#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif


// Not guaranteed that categories are different hmm ! something fishy might happen. But let's assume first this and then if WA then we will change

// Edit1 : WA because of 1)- Wrong output format 2)- Some more mistake

// I would kinda easy problem but lot's of constraints and medium coding also some un-clear statements so i had to assume non - presentce
// 5 min 12 min to read and think
// 13 min and 28 sec to code this solution
// 1 min 35 sec to debug and verify

string F(string s) {
	string res = "";
	for(char ch : s) {
		if(isalpha(ch)) res += ch;
	}
	return res;
}

int main() {
	int qq;
	scanf("%d",&qq);
	while ( qq-- ) {
		int c;
		scanf("%d", &c);
		map<string, int> limit;
		map<string, string> mapper;
		map<string, int> count;
		
		vector<string> order;
		for(int i = 0; i < c; ++i) {
			string key, value;
			int w, p;
			cin >> key >> w >> p;
			limit[key] = p;
			order.push_back(key);
			for(int j = 0; j < w ; ++j) {
				 cin >> value;
				 mapper[value] = key; // yeah it's reverse for storing
			}
		}
		
		cin >> ws; // buffer clear;
		string s, inp;
		while (getline(cin, s ) && s != "") {
			stringstream ss(s);
			while( ss >> inp ) {
				inp = F(inp);
	
				if(mapper.find(inp) != mapper.end()) { // to make sure because what if the P = 0 then we will get WA
					string cat = mapper[inp];
					count[cat]++;
				}
			}
		}
		
		bool ok = false;
		for(auto cat : order) {
			if(count[cat] >= limit[cat]) {
				puts(cat.c_str());
				ok = true;
			}
		}
		if(!ok) puts("SQF Problem.");
	}
		
	return 0;
}
