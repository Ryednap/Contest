#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(qq * sqt(n)) 

int main( ) {
	int qq, tt = 0;
	scanf("%d", &qq);
	
	while( qq-- ) {
		int a, b;
		scanf("%d %d", &a, &b);
		set<int> ans;
		a -= b;
		for(int i = 1; i <= sqrt(a); ++i) { // use set as possible to avoid duplicate cases to check hi , lo, perfect square 0 , 1, prime etc.
			if(a % i == 0) {
				if(i > b) ans.insert(i);
				if(a / i > b) ans.insert(a / i );
			}
		}
		printf("Case #%d:", ++tt);
		for(const int & x : ans) {
			printf(" %d", x);
		}
		if(a == 0) {
			printf(" 0");
		}
		puts("");
	}
	
	return 0;	
}
