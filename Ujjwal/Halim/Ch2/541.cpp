#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

int main( ) {
	int n;
	while( scanf("%d", &n) ) {
		if(!n) break;
		int grid[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d",&grid[i][j]);
			}
		}
		
		vector<int> row(n), col(n);
		for(int i = 0;i < n; ++i) {
			int a = 0, b = 0;
			for(int j = 0; j < n; ++j) {
				a += grid[i][j];
				b += grid[j][i];
			}
			col[i] = b % 2;
			row[i] = a % 2;
		}
		
		vector<pii> ans;
		for(int i = 0; i < n; ++i) {
			if(row[i]) {
				for(int j = 0; j < n; ++j) {
					if(col[j]) {
						col[j] = false; // for 1 rong answer mistake was here instead of i j and vice-versa.
						row[i] = false;
						ans.emplace_back(i, j);
					}
				}
				if(row[i]) { // Note that this is possible that one of the row/col is odd and other odd but this always occurs in pairs. eg is given
					ans.emplace_back(1,1);
					ans.emplace_back(1,1);
				}
			}
			if(col[i]) {
				for(int j = 0; j < n; ++j) {
					if(row[j]) {
						row[j] = col[i] = false;
						ans.emplace_back(j, i);
					}
				}
				if(col[i]) {
					ans.emplace_back(1, 1);
					ans.emplace_back(1, 1);
				}
			}
		}
		if( (int)ans.size() == 0 ) puts("OK");
		else if( (int)ans.size() == 1) printf("Change bit (%d,%d)\n", ans[0].f + 1, ans[0].s + 1);
		else puts("Corrupt");
	}
	
	return 0;	
}

/*
 * 3
1 1 1
1 1 1
1 1 1

3
0 0 0
0 1 0
0 0 0

3
1 0 0
0 1 0
0 0 1

4

1 1 1 1 // tricky case corrupt
1 1 1 1
1 0 0 1
1 1 1 1
0
*/
