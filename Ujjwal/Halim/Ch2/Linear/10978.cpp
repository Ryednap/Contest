#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pss = pair<string, string> ;

#define f first
#define s second

// Challenge : To effectively insert all the cards in the playing feild.
// Counting with indices is the main issue.
// For example our string length is m and we are using 0 based indexing and we need to move m steps what should be the init loop. ? It should be m - 1
// because if we run the loop m times then it will take the index to  0 + m = m i.e m - 0 + 1 = m + 1 steps forward.

// O(n * |s| * n) = O(n^2 |s|) compleixty as the worst case is when we have 1 slot free then we will run through all the slots |s| times where |s| = length
// of the string.

int main( ) {
	int n;
	while( scanf("%d", &n) ) {
		if(n == 0) break;
		vector<pss> cards(n);
		for(auto &p : cards) {
			cin >> p.f >> p.s;
		}
		vector<string> ans(n + 1, "");
		int pos = 0;
		for(auto p : cards) {
			int m = (int)p.s.length() - 1;
			while(m) {
				int i = pos % n;
				if(ans[i] == "") --m;
				++pos;
			}
			while(1) {
				int i = pos % n;
				if(ans[i] == "") break;
				++pos;
			}
			int i = pos % n;
			//debug() << owo(i) owo(pos);
			assert(ans[i] == "");
			ans[i] = p.f;
			++pos;
		}
			
		printf("%s", ans[0].c_str());
		for(int i = 1; i < n; ++i) {
			printf(" %s", ans[i].c_str());
		}
		puts("");
	}
					
	return 0;	
}
