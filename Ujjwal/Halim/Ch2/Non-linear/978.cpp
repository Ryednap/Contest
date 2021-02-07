#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second


// Actually some run-time error even flags are unable to detect it.
// Actually some run-time error even flags are unable to detect it.

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, g, b;
		scanf("%d %d %d",&n, &g, &b);
		set<pii> green, blue;
		for(int i = 0; i < g; ++i) {
			int x; scanf("%d",&x);
			green.insert(make_pair(-x, i));
		}
		for(int j = 0; j < b; ++j) {
			int x; scanf("%d", &x);
			blue.insert(make_pair(-x, j));
		}
		
		auto Insert = [&] (set<pii> &to, set<pii> &from) {
				int cnt = 0;
				while(!from.empty() && cnt != n) {
					auto front = from.begin();
					to.insert(*front);
					from.erase(*front);
					++cnt;
				}
		};
		
		int winner = 0;
		while( true ) {
			if(green.empty()) {
				if(!blue.empty()) winner = 2;
				break;
			} else if(blue.empty()) {
				if(!green.empty()) winner = 1;
				break;
			}
			
			set<pii> sg, sb;
			Insert(sg, green);
			Insert(sb, blue);

			for(auto i = sg.begin(), j = sb.begin(); i != sg.end() || j != sb.end(); ) {
				if(i == sg.end()) {
					while( j != sb.end() ) {
						blue.insert(*j);
						++j;
					}
				} else if(j == sb.end()) {
					while( i != sg.end() ) {
						green.insert(*i);
						++i;
					}
				} else {
					auto p = *sg.begin(); sg.erase(p);
					auto q = *sb.begin(); sb.erase(q);
					int x = abs(p.f);
					int y = abs(q.f);
					x = abs(x);
					y = abs(y);
					if(x > y) {
						green.insert(make_pair(y - x, p.s));
					} else if(y > x) {
						blue.insert(make_pair(x - y, q.s));
					}
					++i, ++j;
				}
			}
		}

		if(!winner) puts("green and blue died");
		else if(winner == 1) {
			puts("green wins");
			for (auto x : green) {
				printf("%d\n", abs(x.f));
			}
		} else {
			puts("blue wins");
			for ( auto x : blue) {
				printf("%d\n", abs(x.f));
			}
		}
		if(qq) puts("");
	}
		
	return 0;
}


