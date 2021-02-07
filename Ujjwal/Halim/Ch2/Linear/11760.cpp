#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int r, c, n, tt = 0;;
	while( scanf("%d %d %d", &r, &c, &n) ) {
		if(!r && !c && !n) break;
		vector<int> row(r + 1, 0), col(c + 1, 0);
		
		for(int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x , &y);
			row[x] = 1;
			col[y] = 1;
		}
		
		int x, y;
		scanf("%d %d", &x, &y);
		
		int dx [] = {0, 0, 0, -1, 1};
		int dy [] = {0, -1,1, 0, 0};
		
		bool ok = false;
		auto Valid = [&](int a, int b) {
			if(a < 0 || b < 0 || a >= r || b >= c) return false;
			return true;
		};
		
		for(int i = 0; i < 5; ++i) {
			int RR = x + dx[i];
			int CC = y + dy[i];
			if(!Valid(RR,CC)) continue;
			if(!row[RR] && !col[CC]) {
				ok = true;
				break;
			}
		}
		printf("Case %d: %s", ++tt, ok ? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!");
		puts("");
	}
		
	return 0;	
}
