#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif


int main( ) {
	int P, C, tt = 0;
	while( scanf("%d %d" , &P, &C) && P && C ) {
		deque<int> q;
		for(int i = 1; i <= min(P, C); ++i) {
			q.push_back(i);
		}
		
		printf("Case %d:\n", ++tt);
		for(int i = 0; i < C; ++i) {
			string s ; cin >> s;
			if(s == "N") {
				int x = q.front(); q.pop_front();
				q.push_back(x);
				printf("%d\n", x);
			} else {
				int x ; scanf("%d", &x);
				auto itr = find(q.begin(), q.end(), x);
				if(itr == q.end()) {
					q.push_front(x);
				} else {
					q.erase(itr);
					q.push_front(x);
				}
			}
		}
	}
	return 0;
}
