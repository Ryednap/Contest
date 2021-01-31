#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// O(N logN)

struct Date {
	string name;
	int dd, mm , yy;
	Date() {}
	bool operator < (const Date & d) const {
		if(yy == d.yy) {
			if(mm == d.mm) {
				return dd > d.dd;
			} else return mm > d.mm;
		} else return yy > d.yy;
	}
}; 

int main( ) {
	int n;
	scanf("%d", &n);
	Date arr[n];
	for(int  i = 0; i < n; ++i) {
		cin >> arr[i].name >> arr[i].dd >> arr[i].mm >> arr[i].yy;
	}
	sort(arr, arr + n);
	printf("%s\n%s\n", arr[0].name.c_str(), arr[n -1].name.c_str());

	return 0;	
}
