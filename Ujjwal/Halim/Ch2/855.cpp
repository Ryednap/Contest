#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;
#define f first
#define s second

// Recommended 

// If such problem occurs then it's better to use mean and median and then check , however median is ans

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, m, f;
		scanf("%d %d %d", &n, &m, &f);
		vector<int> a, b;
		for(int i = 0; i < f; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			a.push_back(x);
			b.push_back(y);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int x = (f >> 1) - !(f & 1); // a way to get middle lowest element in case of even.
		
		printf("(Street: %d, Avenue: %d)\n", a[x], b[x]);
	}
	
	return 0;	
}
