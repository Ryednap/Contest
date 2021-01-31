#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(nlogn) complexity

// The idea is that the median is the answer

/*
 * Proof : Let median be x, and let's assume that it's not answer, then either the answer is x' > x or x' < x , 
 * for x' > x , let's say x' = x + 1. Now F(x) = |a1 - x| + |a2 - x| + |a3 - x| ... , if we see then let p numbers be less than x and q be greater
 * then p + q + 1 = n. now if x' = x + 1. then in the left all the answers will increase by +1 and on right -1 in the sorted order. 
 * total increase = p - q + 1. but p > q as it's median + 1 so net increase > median's value . So inductively we can say for, x' > xthat it's waste, also
 * if we continue going to right eventually q will decrease and p will increase which will increase the net increase which is not min.
 * 
 * also same argument for x' < x it's q - p - 1 . Now one thing to note using this proof method is that if (single median then that's the answer) else (double medain
 * then all the integers (median , median + 1) bettween are possible candidate and same argument as above applies p = q , so net increase is = increase in x
 */

int main( ) {
	int n;
	while( scanf("%d",&n) != EOF ) {
		int arr[n];
		map<int, int> mapper;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			mapper[arr[i]]++;
		}
		sort(arr, arr + n);
		tuple<int,int,int> ans;
		int mid = (n >> 1) - !(n & 1);
		
		if(!(n & 1)) {
			get<0> (ans) = arr[mid];
			if(arr[mid] != arr[mid + 1]) {
				int x = arr[mid];
				int y = arr[mid + 1];
				get<1> (ans) = mapper[x] + mapper[y];
				get<2> (ans) = (y - x + 1);
				
			} else {
				int x = arr[mid];
				get<1> (ans) = mapper[x];
				get<2> (ans) = 1;
			}
			
		} else {
			get<0> (ans) = arr[mid];	
			get<1> (ans) = mapper[arr[mid]];
			get<2> (ans) = 1;
		}
		
		printf("%d %d %d\n", get<0> (ans), get<1> (ans), get<2> (ans));
	}
		
	return 0;	
}
