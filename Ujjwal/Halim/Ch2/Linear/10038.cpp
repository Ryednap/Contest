#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n) easy level : 1
// The problem asks us to check if there exists a permutation of p(n-1) from the difference of the consecutive elements.
// So here comes the use of array over like map or any other data-structre.

int main( ) {
	int n;
	while(scanf("%d",&n) != EOF) {
		int prev;
		scanf("%d", &prev);
		int arr[n] = {0};
		for(int i = 1; i < n ; ++i) {
			int curr;
			scanf("%d", &curr);
			int x = abs(curr - prev);
			if(x < n) arr[x] = 1;
			prev = curr;
		}
		
		bool ok = true;
		for(int i = 1; i < n; ++i) {
			if(!arr[i]) ok = false;
		}
		puts( ok ? "Jolly" : "Not jolly");
	}
	
	return 0;	
}
