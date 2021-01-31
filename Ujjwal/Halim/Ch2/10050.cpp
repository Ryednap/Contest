#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// DAT based problem approach.

int main( ) {
	int qq;
	scanf("%d", &qq) ;
	while( qq-- ) {
		int n, p;
		scanf("%d %d",&n, &p);
		vector<int> arr(n + 1), done((int)1e6, 0);
		for(int i = 0 ; i < p; ++i) {
			int x;
			scanf("%d", &x);
			if(done[x]) continue;
			for(int days = x; days <= n; days += x) arr[days] = 1;
			done[x] = 1;
		}

		int answer = 0,day = 1;
		for(int i = 1; i <= n; ++i) {
			if(day != 6 && day != 7) answer += arr[i] > 0;
			day = (day + 1)%8;
			if(day == 0) ++day;
		}
		printf("%d\n", answer);
	}
	
	return 0;	
}
