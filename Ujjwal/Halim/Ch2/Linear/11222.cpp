#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n) solution based on 1-d Array.

int main( ) {
	int qq;
	scanf("%d", &qq);
	for(int tt = 0; tt < qq; ++tt) {
		printf("Case #%d:\n", tt + 1);
		vector<vector<int>> v(10010); // for every problem
		for(int people = 0; people < 3; ++people) {
			int n;
			scanf("%d", &n);
			for(int i = 0; i < n; ++i) {
				int x;
				scanf("%d", &x);
				v[x].push_back(people);
			}
		}
		
		vector<int> ans[3]; // for every answer 
		for(int i = 0; i < 10010; ++i) {
			if((int)v[i].size() == 1) ans[v[i][0]].push_back(i);
		}
		
		int p = 0; // index to friend who solved more problem
		for(int i = 0; i < 3; ++i) {
			if((int)ans[i].size() > (int)ans[p].size()) p = i;
		}
		
		for(int i = 0; i < 3; ++i) { // search for p
			if((int)ans[i].size() == (int)ans[p].size()) {
				printf("%d %d", i + 1, (int)ans[i].size());
				for(int x : ans[i]) printf(" %d", x);
				puts("");
			}
		}
	}
	
	return 0;	
}
