#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq -- ) {
		cin >> ws;
		string name;
		getline(cin, name);
		map<string, int> cost;
		int n, m, b;
		scanf("%d %d %d",&m, &n, &b);
		for(int i = 0; i < m; ++i) {
			string ing;
			int c;
			cin >> ing >> c;
			cost[ing] = c;
		}
		
		vector<pair<int, string>> ans;
		for(int i = 0; i < n; ++i) {
			cin >> ws;
			string rec;  
			getline(cin, rec);
			int k; scanf("%d", &k);
			int total = 0;
			for(int j = 0; j < k; ++j) {
				string s; int q;
				cin >> s >> q;
				assert(cost.find(s) != cost.end());
				total += cost[s] * q;
			}
			if(total <= b) {
				ans.emplace_back(total, rec);
			}
		}
		
		auto F = [&] (string & str) {
			string rec = "";
			for( auto ch : str) {
				rec += toupper(ch);
			}
			return rec;
		};
		
		puts(F(name).c_str());
		sort(ans.begin(), ans.end());
		if((int)ans.size() != 0) {
			for(auto p : ans) {
				puts(p.second.c_str());
			}
			
		} else {
				puts("Too expensive!");
		}
		//if(qq) puts(""); // was not mentioned fuck all the question say this print blank line even after last case
		puts("");
	}
	return 0;
}


