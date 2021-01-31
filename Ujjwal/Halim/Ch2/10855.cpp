#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Simulation but tough problem
 * complexity is O(N^2 * n^2)
 */ 

int main( ) {
	int N, n;
	while( scanf("%d %d", &N, &n) ) {
		if(!N && !n) break;
		vector<string> big(N), small(n);
		for(int i = 0; i < N; ++i) {
			cin >> big[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> small[i];
		}

		vector<int> ans;
		
		auto Rotate = [&]() { // actually this is anti-clockwise rotation doesn't matter because 270 clock = 90 anti-clock
			vector<string> New(n);
			int curr = 0;
			for(int i = n - 1; i >= 0; --i) {
				for(int j = 0; j < n; ++j) {
					New[curr] += small[j][i];
				}
				++curr;
			}
			small = New;
			//debug() << owo(small);
		};
		
		for(int angle : {0, 90, 90, 90}) {
			if(angle != 0) {
				Rotate();
			}
			int cnt = 0;
			for(int row = 0; row <= N - n; ++row) { //*
				for(int col = 0; col <= N - n; ++col) { //*

					bool ok = true;
					for(int i = row; i < row + n; ++i) {
						for(int j = col; j < col + n; ++j) {
							if(small[i - row][j - col] != big[i][j]) { //*
								ok = false;
								break;
							}
						}
					}
					cnt += ok;
				}
			}
			ans.push_back(cnt);
		}
		printf("%d", ans[0]);
		for(int i = 3; i >= 1; --i) {
			printf(" %d", ans[i]);
		}
		puts("");
	}

	return 0;	
}
