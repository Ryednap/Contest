#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// level 2

/*
 * Just get the minimum difference b/w two island and then if we join, then all the distance is going to decreased by that amount :)
 * O(nlogn) complexity.
 */

int main( ) {
	int n;
	while( scanf("%d", &n) ){
		if(n == 0) break;
		int arr[n];
		cin >> ws;
		for(int i = 0; i < n; ++i) {
			string str;
			getline(cin, str);
			int cnt = 0;
			for(char ch : str) {
				if(ch != 'X') ++cnt;
			}
			arr[i] = cnt;
		}
		sort(arr, arr + n);
		int answer = 0;
		for(int i = 1; i < n; ++i) {
			answer += arr[i] - arr[0];
		}
		printf("%d\n", answer);
	}
			
	return 0;	
}
