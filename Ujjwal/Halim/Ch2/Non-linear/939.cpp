#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// A nice graph kinda problem complexity is same as BFS / DFS O(n) but due to usage of map assume O(nlogn). 

using pss = pair<string, string>;
#define f first
#define s second

int main() {
	int n;
	scanf("%d", &n);
	map<string, int> trait;
	
	auto Gene = [&] (string & s) {
		if(s == "dominant") return 3;
		else if(s == "recessive") return 2;
		else if(s == "non-existent") return 1;
		else return 0;
	};
		
	map<string, vector<string>> parent;
	
	for(int i = 0; i < n; ++i) {
		string a, b;
		cin >> a >> b;
		if(Gene (b) ) {
			trait[a] = Gene(b);

		} else {
			parent[b].push_back(a);
		}
	}
	
	function < int(string & ) > Find = [&] (string & s) {
		if(trait.find(s) != trait.end()) return trait[s];
		else {
			vector<string> &v = parent[s];
			int a = Find(v[0]), b = Find(v[1]);
			if(b > a) swap(a, b);
			if(a == 3 && b == 3) {
				return trait[s] = 3;
			} else if(a == 3 && b == 2) {
				return trait[s] = 3;
			} else if(a == 3) {
				return trait[s] = 2;
			} else if(a == 2 && b == 2) {
				return trait[s] = 2;
			} else return trait[s] = 1;
		}
	};
			
			
	
	for(auto p : parent) {
		string child = p.f;
		int x = Find(child);
		trait[child] = x;
	}
	
	for(auto p : trait) {
		string s = p.f;
		int x = p.s;
		printf("%s ", s.c_str());
		if(x == 3) puts("dominant");
		else if(x == 2) puts("recessive");
		else puts("non-existent");
	}
			
	return 0;
}


