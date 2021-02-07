#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// two pointer technique;

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq -- ) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for(auto & x : v) {
			scanf("%d", &x);
		}
		
		int ans = 0;
		map<int, bool> done;
		for(int i = 0, j = 0; i < n; ++i) {
			while( j < n && !done[v[j]] ) {
				done[v[j++]] = true;
			}
			ans = max(ans, j - i);
			done.erase(v[i]);
		}
		printf("%d\n", ans);			
	}	
	return 0;
}


