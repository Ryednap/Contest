#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// This solution is an upgraded form of the same solution . Now the complexity is the most optimal of O(nm). The idea is same as of single dimensional
// array just we are doing the prefix sum on the two-dimensional array. (One must know how to manipulate).

using vi = vector<int>;

int main( ) {
	int n, m, qq;
	while( scanf("%d %d %d",&n,&m, &qq) ) {
		if(n == 0 && m == 0 && qq == 0) break;
		vector<vi> grid(n + 2, vi(m + 2));
		
		while( qq -- ) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(a > c) swap(a, c);
			if(b > d) swap(b, d);
			
			grid[a][b]++;
			grid[c + 1][b]--;
			grid[a][d + 1]--;
			grid[c + 1][d + 1]++;
		}
		
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				grid[j][i] += grid[j - 1][i];
			}
		}
		for(int i = 1; i <= n + 1; ++i) {
			for(int j = 1; j <= m + 1; ++j) {
				grid[i][j] += grid[i][j - 1];
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
