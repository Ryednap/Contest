#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// Direct easy problem greedy just use up all the best items O(nlogn) complexity.

int main( ) {
	int qq;
	scanf("%d", &qq);
	while( qq-- ) {
		int n;
		scanf("%d", &n);
		int arr[n];
		for(int i = 0 ; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		auto cmp = [](const int & p1, const int & p2) {
			return abs(p1) >= abs(p2);
		};
		
		sort(arr, arr + n, cmp);
		int answer = 1, last = arr[0] < 0;
		for(int i = 1; i < n; ++i) {
			if(last != (arr[i] < 0)) {
				++answer;
				last = arr[i] < 0;
			}
		}
		printf("%d\n", answer);
	}
		
	return 0;	
}
