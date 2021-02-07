#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int x;
	vector<int> arr;
	while( scanf("%d",&x) != EOF) {
		arr.push_back(x);
		sort(arr.begin(), arr.end());
		int n = (int)arr.size();
		if(n & 1) {
			n >>= 1;
			printf("%d\n", arr[n]);
		} else {
			n >>= 1;
			printf("%d\n", (arr[n] + arr[n - 1]) >> 1);
		}
	}
	return 0;	
}
