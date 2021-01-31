#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using pii = pair<int, int>;

#define f first
#define s second
#define sz(x) ((int)x.size())

// tricky case when the time doesnot start with 0, all the ferry are on the one side and there's no ferry 
// Important
// for queue and stack implementation check for any sanitizatoin

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n, t, m;
		scanf("%d %d %d",&n, &t, &m);
		
		array<queue<pii>, 2> bank;
		for(int i = 0; i < m; ++i) {
			int x; string s;
			cin >> x >> s;
			if(s == "left") {
				bank[0].push(make_pair(x, i));
			} else {
				bank[1].push(make_pair(x, i));
			}
		}
		
		int curr = 0, time = 0;
		queue<pii> ferry;
		
		auto Valid = [&]() {
			if(!bank[0].empty()) return true;
			if(!bank[1].empty()) return true;
			return false;
		};
		
		auto Present = [&] (queue<pii> & q) {
			if(q.empty()) return false;
			pii p = q.front();
			if(p.f <= time) return true;
			return false;
		};
		
		auto Load = [&](queue<pii> & q) {
			while(Present(q)) {
				pii p = q.front();  q.pop();
				ferry.push(p);
				if((int)ferry.size() == n) break;
			}
			curr ^= 1;
			time += t;
		};
		
		
		int ans[m];
		while(Valid()) {
			
			if(Present(bank[curr])) {
				Load(bank[curr]);
			
			} else if(Present(bank[curr ^ 1])) {
			
				time += t;
				curr ^= 1;
				Load(bank[curr]);
			
			} else {
				pii a , b;
				if(!bank[curr].empty()) a = bank[curr].front();
				else a = {(int)1e9,0};
				
				if(!bank[curr ^1].empty()) b = bank[curr ^ 1].front();
				else b = {(int)1e9,0};
				
				//debug() << owo(a) owo(b);
				if(a.f < b.f) {
					time = a.f;
				} else {
					time = b.f;
				}					
			}
	
			// unload
			while(!ferry.empty()) {
				pii p = ferry.front() ;   ferry.pop();
				ans[p.s] = time;
			}
		}

		for(int i = 0; i < m; ++i) {
			printf("%d\n", ans[i]);
		}
		if(qq) puts("");
	}
		
	return 0;	
}
