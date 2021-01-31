#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	while( scanf("%d",&n) ) {
		if(n == 0) break;
		vector<int> ans(n + 1, -1);
		bool ok = true;
		
		for(int i = 1 ; i <= n; ++i) {
			int a, b;
			scanf("%d %d",&a, &b);
			int real = i + b;
			if(real < 1 || real > n || ans[real] != -1) {
				ok = false;
			} else ans[real] = a;
		}
		
		if(ok) {
			printf("%d", ans[1]);
			for(int i = 2; i <= n; ++i) {
				printf(" %d",ans[i]);
			}			
			puts("");
		} else puts("-1");
	}
	
	return 0;	
}
