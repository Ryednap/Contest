#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "uj.h"
#endif

int main( ) {
	int n;
	while( scanf("%d", &n) ) {
		if(n == 0) break;
		vector<string> num(n);
		for(int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		
		auto cmp = [] (const string & s1, const string & s2) {
			const int a = (int)s1.length();
			const int b = (int)s2.length();
			int x  = min(a, b);
			string f = s1.substr(0, x);
			string l = s2.substr(0, x);
			if(f == l)
				return a < b;
			else 
				return s1 > s2;
		};	
		debug() << owo(num);
		sort(num.begin(), num.end(), cmp);
	
		for(int i = 0; i < n; ++i) {
			printf("%s", num[i].c_str());
		}
		puts("");
	}
	
	return 0;	
}
