#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * Greedy : We can do binary search to see the minimum but what's the need when we know that average is the best options : 
 * Proof: Well actually there's not need of proof why because if we are to make all the array elements equal and suppose we have n elements then the
 * sum is n * x (x = the value of equal elements). now as we know that this sum is constant then there exist only one x such that n | sum.
 * 
 * O(n) algorithm;
 */

int main( ) {
	int n, tt = 0;
	while( scanf("%d", &n) ){
		if( n == 0)  break;
		int arr[n], sum = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		int x = sum / n;
		assert(sum % x == 0) ;
		int answer = 0;
		for(int i = 0; i < n; ++i) {
			answer += abs(arr[i] - x);
		}
		assert(answer % 2 == 0);
		printf("Set #%d\nThe minimum number of moves is %d.\n", ++tt, answer/2);
		puts("");
	}
			
	return 0;	
}
