#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

// A very nice problem on comparator function on choice

int main( ) {
	int n;
	while( scanf("%d", &n) ) {
		if(n == 0) break;
		vector<string> num(n);
		for(int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		
		auto cmp = [] (const string & s1, const string & s2) { // we don't know adding first s1 or s2 is benificial so we will check both and return max one
			string a = s1 + s2;
			string b = s2 + s1;
			return a > b;
		};	
		sort(num.begin(), num.end(), cmp);
	
		for(int i = 0; i < n; ++i) {
			printf("%s", num[i].c_str());
		}
		puts("");
	}
	
	return 0;	
}

/*
 * Tricky Cases
 * 121 1219  = 1219121
 * 999 99992 = 99999992
 * 
 */
