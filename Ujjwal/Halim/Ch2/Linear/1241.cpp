#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(2^n logn) complexity direct implementation

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> v(1 << n, 1);
		for(int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			v[x - 1] = 0;
		}
		
		int answer = 0;
		while((int)v.size() > 1) {
			vector<int> next;
			for(int i = 0; i < (int)v.size() ; i += 2) {
				next.push_back(v[i] | v[i + 1]);
				if(v[i] && !v[i + 1]) ++answer;
				if(v[i + 1] && !v[i]) ++answer;
			}
			v = next;
		}
		printf("%d\n", answer);
	}
	
	return 0;	
}
