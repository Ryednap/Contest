#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(2^n * n) complexity
// Look at the statement how bogus it is . It's actually want's to say that for any two adjacent corner sum of all the weights of the reachable corner
// from those. Hence once first compute the potency of each corner and then for adjacent we can do that for p[x] + p[y] - w[x] - w[y] because in p[x] +
// p[y] we have counted the weights of corner x and y twice.

int main( ) {
	int n;
	while( scanf("%d", &n) != EOF ) {
		vector<int> store(1 << n);
		for(int i = 0; i < (1 << n); ++i) {
			scanf("%d", &store[i]);
		} 

		vector<int> answer(1 << n);
		for(int i = 0; i < (1 << n ); ++i) {
			int maybe = store[i];
			for(int j = 0; j < n; ++j) {
				int x = (i ^ (1 << j));
				maybe += store[x];
			}
			answer[i] = maybe;
		}
		int ans = 0;
		for(int i = 0; i < (1 << n); ++i) {
			for(int j = 0; j < n; ++j) {
				int x = (i ^ (1 << j));
				ans = max(ans, answer[i] + answer[x] - store[i] - store[x]);
			}
		} 
		printf("%d\n", ans);
	}	
	
	return 0;	
}
