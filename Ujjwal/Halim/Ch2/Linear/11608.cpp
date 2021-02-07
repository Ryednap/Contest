#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif
// Easy problem O(12) solutoin.

int main( ) {
	int n, tt = 0;
	while( scanf("%d", &n) ) {
		if(n < 0) break;
		array<int, 12> a[2];
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 12; ++j) {
				scanf("%d", &a[i][j]);
			}
		}

		printf("Case %d:\n", ++tt);
		for(int i = 0; i < 12; ++i) {
			if(n < a[1][i]) puts("No problem. :(");
			else puts("No problem! :D"), n -= a[1][i];
			n += a[0][i];
		}
	}
	return 0;	
}
