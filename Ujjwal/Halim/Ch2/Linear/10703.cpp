#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// watch for the fucking grammar
// For more optimize version check same file with _2 .

// current complexity is O(nm*qq)

using vi = vector<int>;
int main( ) {
	int n, m, qq;
	while(scanf("%d %d%d", &n, &m, &qq)) {
		if(n == 0 && m == 0 && qq == 0) break;
		vector<vi> grid(n + 2, vi(m + 2));
		
		while(qq -- ) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(a > c) swap(a, c);
			if(d > b) swap(b, d);
			
			for(int i = a; i <= c; ++i) {
				for(int j = d; j <= b; ++j) {
					grid[i][j] = 1;
				}
			}
		}
		
		
		int cnt = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(!grid[i][j]) ++cnt;
			}
		}

		if(cnt == 0) puts("There is no empty spots.");
		else if(cnt == 1) puts("There is one empty spot.");
		else printf("There are %d empty spots.\n", cnt);
	}
	return 0;	
}
