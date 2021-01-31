#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Mostly the concept is same as UVA 11093 JUST FINISH UP JUST INSTED OF CIRCLE WE NEED TO REVERSE THE MOTION.

int main( ) {
	int n;
	while( scanf("%d", &n) ) {
		if(!n) break;
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
		}
		sort(arr, arr + n);
		int fuel = 200, start = 0;
		bool ok = true;
		
		for(int i = 0; i < n; ++i) {
			int x = arr[i] - start;
			if(x > fuel) ok = false;
			else fuel = 200, start =  arr[i];
		}
		
		// initially had forgot these lines which cost me 2 submissions.
		ok &= (1422 - start <= fuel);
		fuel -= (1422 - start);
		start = 1422;
		for(int i = n - 1; i >= 0; --i) {
			int x = start - arr[i];
			if(x > fuel) ok = false;
			else fuel = 200, start = arr[i];
		}
			
		puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
	} 
	
	return 0;	
}
