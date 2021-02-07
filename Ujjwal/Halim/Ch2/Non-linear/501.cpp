#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// had to use ordered set.

template <typename T> using ordered_set = tree<T, null_type, less<T> , rb_tree_tag,
tree_order_statistics_node_update>;

int main() {
	int qq;
	scanf("%d", &qq);
	while( qq -- ) {
		int n, m;
		scanf("%d %d", &n, &m);
		int A[n + 1], u[m];
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for(int j = 0; j < m; ++j) {
			scanf("%d", &u[j]);
		}
		
		ordered_set<pair<int, int>> s;
		int curr = 0;
		for(int i = 0, j = 1; i < m; ++i) {
			while(j <= u[i]) {
				s.insert(make_pair(A[j], j));
				++j;
			}
			printf("%d\n", (*s.find_by_order(curr++)).first);
		}
		if(qq) puts("");
	}
	return 0;
}


