#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(n^2) complexity

// Baddest case is when we have 1 2 3 4 ..5 ... n then we need exactly n - 1 + n - 2 + ... 1 steps that is O(n^2) complexity on the worst.

using pii = pair<int, int>;
#define f first
#define s second

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		queue<pii> q;
		for(int i = 0; i < n; ++i) {
			int x;  scanf("%d", &x);
			q.push(make_pair(x, i));
		}
		// Optimization 1 : instead of this we can maintain let's say a priority queue and then we can check if the queue front is the front of pq.
		auto Printed = [] (queue<pii> v, pii f) {
			while( !v.empty() ) {
				pii x = v.front(); v.pop();
				if(x.f > f.f) return false;
			}
			return true;
		};
		
		bool done = false;
		int answer = 0;
		while(!done) {
			pii x = q.front();  q.pop();
			if(Printed(q, x)) {
				++answer;
				if(x.s == m) done = true;
				
			} else {
				q.push(x);
			}
		}
		printf("%d\n", answer);
	}
	
	return 0;	
}
