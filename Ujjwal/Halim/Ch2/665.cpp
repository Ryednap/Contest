#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// level 3

/* 2(WA) because of the commented part
 * it's easy why ? A little harder version could be when number of elements on both side are not equal
 * Now as we know that both side there are equal element if the symbol is = then all the elements are valid else we actually can't even say on which
 * side the faulty coin lies (Suppose < if the fault is on left means it has less weight and vice - versa). so just check for = and do the operation and
 * in the end check if only one coin remain to be fault else actually we can't determine which one is fault in this problem.
 */

int main( ) {
	int qq;
	scanf("%d", &qq);
	
	while( qq-- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		int arr[n + 1] = {0};
		for(int _ = 0; _ < m; ++_) {
			int p; scanf("%d", &p);
			vector<int> left(p), right(p);
			for(int i = 0; i < p; ++i) scanf("%d", &left[i]);
			for(int i = 0; i < p; ++i) scanf("%d", &right[i]);
			char s[3]; // so the problem was here i was taking initialyy char s[1] lol.
			scanf("%s", s);
			if(s[0] == '=') {
				for(int x : left) arr[x] = 1;
				for(int x : right) arr[x] = 1;
			}
		}
		
		int answer = -1;
		for(int i = 1; i <= n; ++i) {
			if(arr[i] == 0 && answer == -1) answer = i;
			else if(arr[i] == 0) {
				answer = -1;
				break;
			}
		}
		printf("%d\n", answer == -1 ? 0 : answer);
		if(qq) puts("");
	}
	
	return 0;	
}
