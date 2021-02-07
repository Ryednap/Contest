#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// 1 min 59 sec reading and understanding
//  8 min 43 sec coding and debuggging

// 1 WA because there may be a situation where a single owns same stamp more than one but this is not clear from the statement as it says stamps owned only by one person
// also what if total = 0 ?

int main() {
	int qq, tt = 0;
	scanf("%d", &qq);
	while( qq-- ) {
		int n;
		scanf("%d", &n);
		map<int, set<int>> mapper;
		set<int> s[n];
		for(int i = 0; i < n; ++i) {
			int m;  scanf("%d", &m);
			for(int j = 0; j < m; ++j) {
				int x; scanf("%d", &x);
				mapper[x].insert(i);
				s[i].insert(x);
			}
		}

		int net[n];
		int total = 0;
		for(int i = 0; i < n; ++i) {
			int x = 0;
			for(auto k : s[i]) {
				if((int)mapper[k].size() == 1) ++x;
			}
			total += x;
			net[i] = x;
		}
		
		printf("Case %d:", ++tt);
		for(int i = 0; i < n; ++i) {
			if(total != 0) printf(" %.6f", net[i] / (double) total * 100);
			else printf(" %6f",0.0);
			cout << "%";
		}
		puts("");
	}
		
	return 0;
}


