#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// easy level problem.

int main() {
	int qq;
	scanf("%d", &qq);
	while (qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		map<int, int> mapper;
		for(int i = 0; i < n; ++i) {
			int x; scanf("%d", &x);
			mapper[x]++;
		}
		int common = 0;
		for(int j = 0; j < m; ++j) {
			int x; scanf("%d",&x);
			if(mapper.find(x) != mapper.end()) {
				++common;
				mapper[x]--;
				if(mapper[x] == 0) mapper.erase(x);
			}
		}
		
		printf("%d\n", n + m - 2 * common);
	
	}
		
	return 0;
}


