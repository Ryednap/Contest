#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Custom sort :- Altough easy but please read the comp function criteria in the c++ manual . it says that if comp(a,b) = true then comp(b, a) = false
 * and comp(a, a) = false. If your custom comp function doesnot satisfy above criteria then u will get heap overflow.
 * O(n logn)
 */

int main( ) {
	int n, m;
	while( scanf("%d %d", &n, &m) != EOF-0 ) {
		printf("%d %d\n", n, m);
		if(n == 0 && m == 0) break;
		int arr[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		auto cmp = [&](const int & a, const int  & b) {
			int x = a % m;
			int y = b % m;
			if(x == y) {
				bool f = a & 1;
				bool s = b & 1;
				if(f && s) return a > b;
				else if(!f && !s) return a < b;
				else return f;
			
			} else return x < y;
		};
		sort(arr, arr + n, cmp);
		
		for(int i = 0; i < n; ++i) {
			printf("%d\n", arr[i]);
		}
	}
	return 0;	
}
