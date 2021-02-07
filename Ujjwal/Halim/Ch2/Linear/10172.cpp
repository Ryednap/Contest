#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

#define sz(x) ((int)x.size())

int main( ) {
	int qq;
	scanf("%d",&qq);
	while(qq--) {
		int N, S, Q;
		scanf("%d %d %d", &N, &S, &Q);
		vector<deque<int>> vs(N);
		stack <int> s;
		
		for(int i = 0; i < N; ++i) {
			int n; scanf("%d", &n);
			for(int box = 0; box < n; ++box) {
				int x ; scanf("%d", &x);
				vs[i].push_back(x - 1);
			}
		}
		
		auto Valid = [&]( ) {
			for(auto q : vs) {
				if(!q.empty()) return true;
			}
			return false;
		};
		
		int ans = 0, i = 0;
		while(Valid()) {
			deque<int> & q = vs[i];

			while(!s.empty()) {
				int x = s.top();
				if(x != i) {	
					if(sz(q) == Q) break;
					else q.push_back(x);
				}
				ans += 1;
				s.pop();
			}
			
			while(!q.empty()) {
				int x = q.front();
				if(sz(s) == S) break;
				else s.push(x);
				q.pop_front();
				ans += 1;
			}
			
			i = (i + 1)%N;
			if(Valid()) ans += 2;
		}

		printf("%d\n", ans);
	}
	return 0;	
}
