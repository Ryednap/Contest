#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// nice problem.
// Complexity is O(n)
// In this problem we learn how to solve circular problem from duplicating array.

int main( ) {
	int qq;
	scanf("%d" , &qq) ;
	
	for(int tt = 0; tt < qq; ++tt) {
		printf("Case %d: ", tt + 1);
		int n;
		scanf("%d" , &n);
		int p[2*n], q[2*n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &p[i]);
		}
		for(int i = 0; i < n; ++i) {
			scanf("%d", &q[i]);
		}
		for(int i = n; i < 2 * n; ++i) {
			p[i] = p[i - n];
		}
		for(int i = n; i < 2 * n; ++i) {
			q[i] = q[i - n];
		}
		
		int answer = -1, curr = p[0], start = 0;
		for(int i = 1; i < 2 * n; ++i) {
			curr -= q[i - 1];
			if(curr < 0) curr = p[i], start = i;
			else curr += p[i];
			if(i - start == n) {
				answer = start;
				break;
			}
		}
		
		if(answer == -1) puts("Not possible");
		else printf("Possible from station %d\n", answer + 1);
	}
	return 0;	
}
