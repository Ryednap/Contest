#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "uj.h"
#endif

// 			E  N  W  S
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;

#define f first
#define s second

int main() {
	int n, m;
	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0) break;
		
		vector<vi> grid(n , vi(m));
		for(int i = 0; i < n; ++i) {
			string inp;  cin >> inp;
			for(int j = 0; j < m; ++j) {
				grid[i][j] = inp[j] - '0';
			}
		}
		debug() << owo(grid);
		
		int ans[n][m] = {0};
		queue<piii> q;
		q.push( {{n - 1, 0}, 0});
		
		auto Add = [] (int c) {
			return (c + 1)%4;
		};
		auto Sub = [] (int c ) {
			return ( ( c - 1)%4 + 4)%4;
		};
		
		auto Valid = [&](int x, int y) {
			if(x < 0 || y < 0 || x >= n || y >= m) return false;
			return grid[x][y] != 1 && Wall(x, y);
		};
		
		auto Wall = [&] (int x, int y, int p) {
			p = Sub(p);
			x = x + dx[p];
			y = y + dy[p];
			return !Valid(x, y);
		};
		
		int cnt = 0, pp = 0;
		while(1) {
			piii el = q.front();  q.pop();
			debug() << owo(el);
			int x = el.f.f, y = el.f.s, l = el.s;
			
			if(x == n && y == 1) {
				++cnt;
				if(cnt == 2) break;
			}
			
			if(!Wall(x, y, l)) l = Add(l);
			
			while(1) {
				int new_x = x + dx[l];
				int new_y = y + dy[l];
				debug() << owo(new_x) owo(new_y) owo(l);
				if(Valid(new_x, new_y)) {
					x = new_x;
					y = new_y;
					break;
				} else l = Add(l);
			} 
			++pp;
			debug() << owo("after") owo(x) owo(y) owo(l);
			if(pp == 9) break;
			q.push( {{x, y}, l});
		}
	}
	return 0;
}
