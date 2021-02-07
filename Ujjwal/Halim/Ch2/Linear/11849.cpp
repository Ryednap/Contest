#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n, m;
	while( scanf("%d %d", &n, &m) && n && m ) {
		set<int> a, b;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			a.insert(x);
		}
		for(int j = 0; j < m; ++j) {
			int x; scanf("%d",&x);
			b.insert(x);
		}
		
		vector<int> ans(max(n, m));
		auto x = set_intersection (a.begin(), a.end(), b.begin(), b.end(), ans.begin());
		printf("%d\n", (int)(x - ans.begin()));
	}
	
	return 0;	
}
