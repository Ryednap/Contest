#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

/*
 * This solution is upgradation on previous with now the complxity is O(nlogn + n) and O(n) memory complexity.
 * The idea is still same just sort the sequence now we for the minimum just find 
 *  Usage of two pointer techniequ.
 */ 

int main( ) {
	int qq;
	scanf("%d", &qq);
	
	while( qq-- ) {
		int n;
		scanf("%d", &n);
		vector<int> a(n), b(n), done(n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int total = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d",&b[i]);
			total += b[i];
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		
		int mini = 0, maxi = 0;
		assert(a[0] == b[0]); // yeah this needs to be true why ? well if that's not true then that's not maximum because col in which max row el is present
							  // will make the max of that row to this.
							  
		for(int i = 0, j = 0; i < n;  ++i) { // we will try to match each a with b and then add all the b that are left unmatched because we need to atleast fullfill each row and col condn
											 // so we can only minimise if we can find a valid pair a[i] = b[j] then we need to include only single copy of them else we need to count both of them.
			while(j < n && a[i] < b[j] ) {
				++j;
			}
			if(j < n && a[i] == b[j]) {
				done[j ++] = true;
			}
			mini += a[i];
		}
		
		for(int i = 0; i < n; ++i) {
			if(!done[i]) mini += b[i];
		}
		
		for(int i = 0, j = 0; i < n; ++i) {// for them maximum for a[i] we have this   x x x x x a[i] y y y y y  where x and y are all the elements in b less than and greater than a[i] respectively.
			
			while( j < n && a[i] <= b[j] ) {
				total -= b[j];
				++j;
			}
			maxi += total + a[i] * (j);
		}

		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mini, maxi - mini);
	}

	return 0;	
}
