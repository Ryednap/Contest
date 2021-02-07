#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

#define f first
#define s second

// Easy problem but implementation heavy 
// 1 WA because of misunderstanding of the blank dict. I thought it as blank line so it created problem.

// 3 min 30 sec for reading and understanding
// 27 : 23 min for coding
// 2 min for debugging

using pss = pair<string, string>;
static pss Extract (string & s) {
	string key = "", inp = "";
	string value;
	
	stringstream ss(s);
	while( getline(ss, inp, ':') ) { // check
		if(isdigit(inp[0])) value = inp;
		else key = inp;
	}
	return make_pair(key, value);
}

int main() {
	int qq;
	scanf("%d", &qq);
	cin >> ws; // clear buff
	while (qq--) {
		string s[2], inp;
		map<string, string> mapper[2];
		for(int i = 0 ; i < 2; ++i) {
			cin >> s[i];
			s[i].erase(s[i].begin());
			s[i].erase(s[i].end() - 1);
			stringstream ss(s[i]);
		
			while ( getline(ss, inp, ',' ) ){
				auto p = Extract(inp);
				mapper[i][p.f] = p.s;
			}
		}
		
		map<string, bool> done;
		vector<string> add, remove, change;
		
		for(auto p : mapper[1]) {
			if(mapper[0].find(p.f) != mapper[0].end()) { // key exists
				if(mapper[0][p.f] != p.s) change.push_back(p.f);
			} else {
				add.push_back(p.f);
			}
			done[p.f] = true;
		}
		
		for (auto p : mapper[0]) {
			if(!done[p.f]) remove.push_back(p.f);
		}
		
		auto Sort = [&] (vector<string> & v) {
			sort(v.begin(), v.end());
		};
		
		Sort(add); Sort(remove); Sort(change);
		bool printed = false;
		string symbol [] = {"+", "-", "*"};
		int j = 0;
		for (auto ans : {add, remove, change} ) {
			bool ok = false;
			if(!ans.empty()) printf("%s%s", symbol[j].c_str(), ans[0].c_str()), ok = true; // check
			for(int i = 1; i < (int)ans.size(); ++i) {
				printf(",%s", ans[i].c_str());
			}
			if(ok) puts("");
			printed |= ok;
			++j;
		}
		
		if(!printed) puts("No changes");
		//if(qq) puts("");
		puts("");
	}
		
	return 0;
}


