#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// current complixity is O(nmK*4).

const int dx [] = {-1, 1, 0, 0};
const int dy [] = {0, 0, -1, 1};
using vi = vector<int>;

int main( ) {
	int n, r, c, k;
	while( scanf("%d %d %d %d", &n, &r, &c, &k)) {
		if(n == 0 && r == 0 && c == 0 && k == 0) break;
		vector<vi> grid(r, vi(c));
		for(int row = 0; row < r; ++row) {
			for(int col = 0; col < c; ++col) {
				scanf("%d", &grid[row][col]);
			}
		}
		
		for(int battles = 0; battles < k; ++battles) {
			vector<vi> done(r, vi(c, 0));
			
			auto Valid = [&](int a, int b, int x, int y) {
				if( a < 0 || b < 0 || a >= r || b >= c ) return false;
				if(done[a][b]) return false;
				return (grid[x][y] + 1)%n == grid[a][b];
			};
			
			vector<vi> New = grid;
			for(int i = 0; i < r; ++i) {
				for(int j = 0; j < c; ++j) {
					for(int cor = 0; cor < 4; ++cor) {
						int x = i + dx[cor];
						int y = j + dy[cor];
						if(Valid(x, y, i , j)) {
							New[x][y] = grid[i][j];
							done[x][y] = true;
						}
					}
				}
			}
			grid = New;
		}
		
		for(int i = 0; i < r; ++i) {
			printf("%d", grid[i][0]);
			for(int j = 1; j < c; ++j) {
				printf(" %d", grid[i][j]);
			}
			puts("");
		}
	}
		
	return 0;	
}
