#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Greedy : We will select the most costliest first, (Watch out for overflow)
// O(nlogn)

int main( ) {
	int qq;
	scanf("%d", &qq) ;
	while( qq-- ) {
		vector<int> price;
		int x;
		while( scanf("%d", &x) ) {
			if( x == 0) break;
			price.push_back(x);
		}
		sort(price.rbegin(), price.rend());
		long long answer = 0;
		for(int i = 0; i < (int)price.size(); ++i) {
			answer += pow((long long)price[i], (long long)i + 1);
		}
		answer *= 2;

		if(answer <= 5000000) printf("%lld\n", answer);
		else puts("Too expensive");
	}
	return 0;	
}
