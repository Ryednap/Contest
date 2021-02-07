#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// A nice intro to range problem solving in 1d array.
// O(n) complexity.

// when [l, r] is cleared then the member to the left of l now contains right of r as it's right element and similarly reverse .

int main( ) {
	int n, m;
	while(scanf("%d %d", &n, &m) ) {
		if(n == 0 || m == 0) break;
		pii arr[n + 1];
		for(int i = 2; i < n; ++i ) {
			arr[i] = make_pair(i - 1, i + 1);
		}
		arr[1] = make_pair(0, 2);
		arr[n] = make_pair(n - 1, 0);
	
		for(int i = 0; i < m; ++i) {
			int l, r;
			scanf("%d %d",&l, &r);
			int a = arr[l].f;
			int b = arr[r].s;
			if(a) printf("%d ", a);
			else printf("* ");
			if(b) printf("%d", b);
			else printf("*");
			puts("");
			arr[a].s = b;
			arr[b].f = a;
		}
		puts("-");
	}
	return 0;	
}
