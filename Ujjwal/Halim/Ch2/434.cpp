#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

const int nax = (int)1e4 + 10;
// important
// O(n^2) solution for optimized look other of the same name with subsript _2.
// Mistakes 1:) if for a[i] == b[j] what i was doing is making all the b[j] that are equal to a[i] on this this is wrong (2,2,2 and 2,2,2)

int main( ) {
	int n, qq;
	scanf("%d", &qq);
	while( qq -- ) {
		scanf("%d", &n);
		int a[n], b[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d",&a[i]);
		}
		for(int j = 0; j < n; ++j) {
			scanf("%d", &b[j]);
		}
		
		int mini = 0, maxi = 0;
		int row[n] = {0}, col[n] = {0}; // row for a and col for b;
		for(int i = 0; i < n; ++i) {
			bool ok = false;
			for(int j = 0; j < n ; ++j) {
				if(!col[j] && a[i] == b[j] && !ok) {
					col[j] = row[i] = true;
					mini += a[i]; // first attempt for mini is to match equal row to equal col.
					ok = true;
				}
				maxi += min(a[i], b[j]); // maximum is quite easy for each cell of the matrix just pick the minimum of the corresponding row or col.
			}
		}
		
		for(int i = 0; i < n; ++i) { // the remaining col elements doesnot really contribute towards any row so just pick a row which is larger than it
			if(!col[i]) {
				for(int j = 0; j < n; ++j) {
					if(a[j] >= b[i]) {
						mini += b[i];
						break;
					}
				}
			}
			if(!row[i]) { // similarly for row.
				for(int j = 0; j < n; ++j) {
					if(b[j] >= a[i]) {
						mini += a[i];
						break;
					}
				}
			}
		}
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mini, maxi - mini);
	}
	return 0;	
}
