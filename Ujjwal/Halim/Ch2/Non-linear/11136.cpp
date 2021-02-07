#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// Level 1 problem 

// 8 min reading and understanding
// 6 min coding
// 1 min 12 min debugging

int main() {
	int n;
	while( scanf("%d", &n) && n ) {
		set<pii> s; // use pair in sets because for trivial multiset.erase(element) removes all the same element . Other impl. maybe to pass iterator.
		int cnt = 0;
		long long total = 0;
		for(int i = 0; i < n; ++i) {
			int m ; scanf("%d", &m);
			for(int j = 0; j < m; ++j) {
				int x; scanf("%d", &x);
				s.insert(make_pair(x, ++cnt));
			}
			auto a = *s.begin();
			auto b = *s.rbegin();
			int x = a.f;
			int y = b.f;
			s.erase(a);
			s.erase(b);
			total += y - x;
		}
		printf("%lld\n", total);
	}
	return 0;
}


