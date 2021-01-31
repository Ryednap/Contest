#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	while( scanf("%d",&n) && n) {
		queue<int> q;
		vector<int> ans;
		for(int i = 1; i <= n; ++i) {
			q.push(i);
		}
		while((int)q.size() > 1) {
			int x = q.front(); q.pop();
			ans.push_back(x);
			x = q.front(); q.pop();
			q.push(x);
		}
	
		printf("Discarded cards:");
		if((int)ans.size() != 0) printf(" %d", ans[0]);
		for(int i = 1; i < (int)ans.size() ; ++i) {
			printf(", %d", ans[i]);
		}
		puts("");
		printf("Remaining card: %d\n", q.front());
	}
	return 0;	
}
