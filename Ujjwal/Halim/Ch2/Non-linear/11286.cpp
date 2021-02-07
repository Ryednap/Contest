#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// Easy level problem

#define s second

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		map<vector<int>, int> count;
		for(int i = 0; i < n; ++i) {
			vector<int> v;
			for(int j = 0; j < 5; ++j) {
				int x; scanf("%d", &x);
				v.push_back(x);
			}
			sort(v.begin(), v.end());
			count[v]++;
		}
		int maxi = 0;
		for(auto p : count) {
			maxi = max(maxi, p.s);
		}
		int ans = 0;
		for(auto p : count) {
			if(p.s == maxi) ans += maxi;
		}
		printf("%d\n", ans);
	}
		
	return 0;
}


