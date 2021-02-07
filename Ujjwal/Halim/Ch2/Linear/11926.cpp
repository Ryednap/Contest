#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// complexity is O(n + m * r);

// It may not be the best but is a good complexity given that i am not using an extra loop for looping across ranges.

const int nax = (int)1e6 + 1;

int main( ) {
	int n, m;
	while( scanf("%d %d", &n, &m) ) {
		if(!n && !m) break;
		
		array<int, nax> ar = {0};
		for(int i = 0; i < n; ++i) {
			int l, r;
			scanf("%d %d", &l, &r);
			ar[l + 1]++;
			ar[r + 1]--;
		}
		
		for(int i = 0 ; i < m; ++i) {
			int l, r, t;
			scanf("%d %d %d", &l, &r, &t);
			while(l < nax) {
				ar[l + 1] ++;
				if(r + 1 < nax) ar[r + 1]--;
				l += t;
				r += t;
			}
		}
		
		for(int i = 1; i < nax; ++i) {
			ar[i] += ar[i - 1];
		}
		
		bool ok = true;
		for(int i = 0; i < nax; ++i) {
			if(ar[i] > 1) {
				ok = false;
				break;
			}
		}
		puts(ok ? "NO CONFLICT" : "CONFLICT");
		
	}
	
	return 0;	
}
