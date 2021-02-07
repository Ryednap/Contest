#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

struct el {
	int a, b;
	el () {}
	el (int x, int y ) : a(x), b(y) {}
	bool operator < (const el & e) const {
		if(b == e.b) {
			return a > e.a;
		} else return b > e.b;
	}
};

int main() {
	string str;
	priority_queue<el> q, r;
	while ( cin >> str && str != "#" ) {
		int id, period;
		scanf("%d %d", &id, &period);
		q.push(el(id, period));
	}
	
	int qq;
	scanf("%d",&qq);
	while( qq-- ) {
		if(q.empty()) q = r;
		el e = q.top(); q.pop();
		printf("%d\n", e.a);
		r.push(e);
	}
	return 0;
}


