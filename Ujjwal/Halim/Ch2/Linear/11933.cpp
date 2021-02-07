#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	
	while( scanf("%d", &n) ) {
		if(!n) break;
		bitset<32> a, b;
		int i = 1;
		while(n) {
			int bit = log2(n & (-n));
			if(i & 1) a[bit] = 1;
			else b[bit] = 1;
			n &= (n - 1);
			++i;
		}
		printf("%lu %lu\n", a.to_ulong(), b.to_ulong());
	}
	
	return 0;	
}
