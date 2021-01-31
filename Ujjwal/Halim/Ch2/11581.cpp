#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

using vi = vector<int>;

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		
		vector<vi> grid(3, vi(3));
		for(int i = 0; i < 3; ++i ) {
			string str;
			cin >> str;
			for(int j = 0; j < 3; ++j) {
				grid[i][j] = str[j] - '0';
			}
		}
		
		auto Valid = [&](int x, int y ) {
			return (x >= 0 && y >= 0 && x < 3 && y < 3);
		};
		
		auto Transform = [&]() {
			vector<vi> New(3, vi(3));
			int dx[] = {-1, 1, 0, 0};
			int dy[] = {0, 0, -1, 1};
			for(int i = 0; i < 3; ++i) {
				for(int j = 0 ; j < 3; ++j) {
					int sum = 0;
					for(int k = 0; k < 4; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if(Valid(x, y)) {
							sum += grid[x][y];
						}
					}
					sum %= 2;
					New[i][j] = sum;
				}
			}
			grid = New;
		};
		
		
		auto Found = [&]() {
			for(int i = 0; i < 3 ; ++i) {
				for(int j = 0; j < 3; ++j) {
					if(grid[i][j] != 0) return false;
				}
			}
			return true;
		};
		
		int iterations = 0;
		bool ok = false;
		map<vector<vi> , bool> done;
		done[grid] = true;
		while(iterations < (int)1e4) {
			Transform();
			if(done[grid]) break;
			else if(Found()) {
				ok = true;
				break;
			} else {
				done[grid] = true;
				++iterations;
			}
		}
		if(ok) printf("%d\n", iterations);
		else puts("-1");
	}
	
	return 0;	
}
